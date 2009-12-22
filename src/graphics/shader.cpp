/* 
 * File:   shader.cpp
 * Author: seanc
 * 
 * Created on May 27, 2009, 5:18 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <lavish/shader.hpp>
#include <lavish/platform.hpp>
#include <iostream>
#include <fstream>

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
        // TODO: make a proper exception type!
        throw "Failed to load shader";
    }
}


Shader::~Shader()
{
    Dispose();
}


bool Shader::Load(std::string filename, shader::Type type)
{
	this->type = type;
	
	std::ifstream file(filename.c_str());
	
	if(!file.is_open())
	{
		return false;
	}
	
	// load file into memory for opengl processing
	char* shaderSource = (char*)malloc(sizeof(char) * MAX_SHADER_SOURCE_LINE_SIZE * MAX_SHADER_SOURCE_LINES);
	const GLchar** shaderSourcePtr = (const GLchar**)&shaderSource;
	int len;
	
	while (!file.eof())
	{
		file.getline(shaderSource, MAX_SHADER_SOURCE_LINE_SIZE);
		len = strlen(shaderSource);
		shaderSource[len] = '\n';
		shaderSource += len + 1;
	}
	shaderSource[len + 1] = 0;
	
	
	// load shader into opengl
	glId = glCreateShader(type);
	glShaderSource(glId, 1, shaderSourcePtr, NULL);
	glCompileShader(glId);
	
	free(shaderSource);
	
	file.close();
	
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

unsigned int Shader::Id()
{
	return glId;
}
	
shader::Type Shader::Type()
{
	return type;
}
        
}
