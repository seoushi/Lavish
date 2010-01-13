/* 
 * File:   model.cpp
 * Author: Sean Chapel
 *
 * Created on Jan 08, 2010, 5:40 PM
 * Copyright 2010 Seoushi Games. All rights reserved.
 */

#include <fstream>

#include <lavish/platform.hpp>
#include <lavish/model.hpp>
#include <lavish/exception.hpp>

namespace lavish
{	

	Model::Model()
	{
		resourceType = resource::Model;
		this->filename = "";
	}

	
	Model::Model(std::string filename)
	{
		resourceType = resource::Model;
		
		if(! Load(filename) )
		{
			throw LAVISH_EXCEPTION("Failed to load model");
		}
	}

	
	Model::~Model()
	{
		Dispose();
	}

	
	bool Model::Load(std::string filename)
	{
		this->filename = filename;
		uint length = filename.length();
		
		//.obj loader
		if((length > 4) && (filename[length - 4] == '.')
						&& (filename[length - 3] == 'o')
						&& (filename[length - 2] == 'b')
						&& (filename[length - 1] == 'j'))
		{
			return loadObj();
		}
		
		return false;
	}
		

	void Model::Dispose()
	{
		buffer.Dispose();
		isResourceLoaded = false;
	}

	
	bool Model::Reload()
	{
		Dispose();
		return Load(filename);
	}


	void Model::Render(Matrix4* transformations)
	{
		glLoadMatrixf(transformations->data);
		
		buffer.Bind();
		glDrawArrays(GL_TRIANGLES, 0, buffer.NumElements());
		buffer.Unbind();
	}


	bool Model::loadObj()
	{
		std::ifstream file;
		file.open(filename.c_str(), std::ios::in);
		
		if(!file.is_open())
		{
			return false;
		}
		
		
		std::string element;
		
		std::vector<Vector3> normals;
		std::vector<Vector3> vertices;
		std::vector<Vector2> texCoords;
		
		std::vector<uint> faceVerts;
		std::vector<uint> faceTexCoords;
		std::vector<uint> faceNormals;
		
		Vector2 tmpV2;
		Vector3 tmpV3;
		
		//Parse file into elements
		while(!file.eof())
		{
			file >> element;
			
			if((element == "#") || (element == "s") || (element == "usemtl"))
			{
				getline(file, element);
			}
			else if(element == "vn")
			{
				file >> element;
				tmpV3.x = atof(element.c_str());
				file >> element;
				tmpV3.y = atof(element.c_str());
				file >> element;
				tmpV3.z = atof(element.c_str());
				
				normals.push_back(tmpV3);
			}
			else if(element == "vt")
			{ 
				file >> element;
				tmpV2.x = atof(element.c_str());
				file >> element;
				tmpV2.y = atof(element.c_str());
				
				texCoords.push_back(tmpV2);
			}
			else if(element == "v")
			{
				file >> element;
				tmpV3.x = atof(element.c_str());
				file >> element;
				tmpV3.y = atof(element.c_str());
				file >> element;
				tmpV3.z = atof(element.c_str());
				
				vertices.push_back(tmpV3);
			}
			else if(element == "f") // Note this only supports triangles, quad faced objects need to be split
			{
				char* tok;
				
				// do each vert
				for(uint i = 0; i < 3; i++)
				{
					file >> element;
				
					tok = strtok(&element[0],"/");
					faceVerts.push_back(atoi(tok) - 1); // -1 is to make it 0 index based
				
					tok = strtok(NULL,"/");
					if(tok != NULL)
					{
						faceTexCoords.push_back(atoi(tok) - 1); // -1 is to make it 0 index based
					}
				
					tok = strtok(NULL,"/");
					if(tok != NULL)
					{
						faceNormals.push_back(atoi(tok) - 1); // -1 is to make it 0 index based
					}
				}
			}
		}

		file.close();
		
		
		// if there are no texture coords make one and set it to 0,0
		if(texCoords.size() == 0)
		{
			texCoords.push_back(Vector2(0,0));
			
			// add texture coord to all face texture coords
			for(uint i = 0; i < faceVerts.size(); i++)
			{
				faceTexCoords.push_back(0);
			}
		}
		
		// if there are no normals calcuate them
		if(normals.size() == 0)
		{
			std::vector<uint> numFacesAttachedToVert;
			
			//create and zero out all normals
			for(uint i = 0; i < vertices.size(); i++)
			{
				normals.push_back(Vector3(0,0,0));
				numFacesAttachedToVert.push_back(0);
			}
			
			for(uint i = 0; i < faceVerts.size(); i++)
			{
				faceNormals.push_back(i);
			}

			uint v1Idx;
			uint v2Idx;
			uint v3Idx;
			
			Vector3 v1;
			Vector3 v2;
			Vector3 v3;
			Vector3 faceNormal;
			
			//calculate all face normals and added them to the vert normal
			for(uint i = 0; i < faceVerts.size(); i += 3)
			{
				v1Idx = faceVerts[i];
				v2Idx = faceVerts[i + 1];
				v3Idx = faceVerts[i + 2];
				
				v1 = vertices[v1Idx];
				v2 = vertices[v2Idx];
				v3 = vertices[v3Idx];

				faceNormal = (v2 - v1) ^ (v3 - v1);

				normals[v1Idx] += faceNormal;
				normals[v2Idx] += faceNormal;
				normals[v3Idx] += faceNormal;
				
				numFacesAttachedToVert[v1Idx]++;
				numFacesAttachedToVert[v2Idx]++;
				numFacesAttachedToVert[v3Idx]++;
			}
			
			// average out all the normals
			for(uint i = 0; i < normals.size(); i++)
			{
				normals[i] /= numFacesAttachedToVert[i];
			}
		}

		buffer.SetSize(faceVerts.size());
		
		// make vertex buffer from data
		for(uint i = 0; i < faceVerts.size(); i++)
		{
			buffer.AddElement(VertexNormalTexture(vertices[faceVerts[i]], normals[faceNormals[i]], texCoords[faceTexCoords[i]]));
		}
		
		buffer.Generate();
		
		return true;
	}

	
} /* lavish */
