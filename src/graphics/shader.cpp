/* 
 * File:   shader.cpp
 * Author: seanc
 * 
 * Created on May 27, 2009, 5:18 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include <lavish/graphics/shader.hpp>
#include <lavish/core/platform.hpp>
#include <lavish/core/exception.hpp>

#define MAX_SHADER_SOURCE_LINE_SIZE 256
#define MAX_SHADER_SOURCE_LINES 512

namespace lavish
{


Shader::Shader()
{
    glId = 0;
    resourceType = resource::Shader;
}


Shader::Shader(std::string filename, shader::Type type)
{
    resourceType = resource::Shader;
    glId = 0;

    if(!Load(filename,type))
    {
		throw LAVISH_EXCEPTION("Failed to load shader");
    }
}


Shader::~Shader()
{
    Dispose();
}


bool Shader::Load(std::string filename, shader::Type type)
{
	this->type = type;
	
	std::ifstream file;
	file.open(filename.c_str(), std::ios::in);
	
	if(!file) 
	{
		return false;
	}
    
	// get file length
	file.seekg (0, std::ios::end);
	int len = (int)file.tellg();
	file.seekg (0, std::ios::beg);
    
	if(len == 0) 
	{
		return false;
	}
    
	
	GLchar* ShaderSource = (GLchar*) new char[len+1];
	ShaderSource[len] = 0; 
	
	// read in the shader
	unsigned int i = 0;
	
	while (file.good())
	{
		ShaderSource[i] = file.get();
		
		if (!file.eof())
		{
			i++;
		}
	}
    
	ShaderSource[i] = 0;
    
	file.close();

	const GLchar** ShaderSourcePtr = (const GLchar**)&ShaderSource;
	
	// load shader into opengl
	glId = glCreateShader(type);
	glShaderSource(glId, 1, ShaderSourcePtr, NULL);
	glCompileShader(glId);
	
	// make sure it's valid
	GLint status;
	glGetShaderiv(glId, GL_COMPILE_STATUS, &status);
	
	if (status == 0)
	{
		glDeleteShader(glId);
		return false;
	}

	return true;
}

void Shader::Dispose()
{
    if(isResourceLoaded)
    {
        glDeleteShader(glId);
		glId = 0;
        isResourceLoaded = false;
    }
}

bool Shader::Reload()
{
    Dispose();
    return Load(resourceName, type);
}
	
shader::Type Shader::Type()
{
	return type;
}
        
}
