/* 
 * File:   model.cpp
 * Author: Sean Chapel
 *
 * Created on Jan 08, 2010, 5:40 PM
 * Copyright 2010 Seoushi Games. All rights reserved.
 */

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
		// TODO: analyze the file name and call the apropriate loading function
		this->filename = filename;
		
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
		// TODO: Implement
	}


	bool Model::loadObj()
	{
		// TODO: Implement
		return false;
	}

	
} /* lavish */
