/* 
 * File:   ShaderSet.cpp
 * Author: seanc
 * 
 * Created on May 27, 2009, 5:18 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include "ShaderSet.hpp"
#include "Platform.hpp"
#include <iostream>
#include <fstream>


namespace lavish
{
	ShaderSet::ShaderSet()
	{
		glId = glCreateProgram();
	}
	
	ShaderSet::~ShaderSet()
	{
		glDeleteProgram(glId);
	}
	
	void ShaderSet::AddShader(Shader* shader)
	{
		glAttachShader(glId, shader->glId);
	}
	
	void ShaderSet::RemoveShader(Shader* shader)
	{
		glDetachShader(glId, shader->glId);
	}
	
	void ShaderSet::Finalize()
	{
		glLinkProgram(glId);
	}
	
	void ShaderSet::Bind()
	{
		glUseProgram(glId);
	}
	
	void ShaderSet::Unbind()
	{
		glUseProgram(0);
	}
	
	GLint ShaderSet::GetUniformId(std::string uniform)
	{
		return glGetUniformLocation(glId, uniform.c_str());
	}
}
