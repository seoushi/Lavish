/* 
 * File:   texture.cpp
 * Author: seanc
 * 
 * Created on May 27, 2009, 3:11 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <iostream>

#include <lavish/graphics/texture.hpp>
#include <lavish/core/platform.hpp>
#include <lavish/core/exception.hpp>


namespace lavish
{


Texture::Texture(unsigned int glId, unsigned int width, unsigned int height) {
	this->glId = glId;
	this->width = width;
	this->height = height;

	if(width != 0 && height != 0){
		isResourceLoaded = true;
	}
}


Texture::~Texture()
{
    Dispose();
}


unsigned int Texture::Width()
{
    return width;
}


unsigned int Texture::Height()
{
    return height;
}


void Texture::Dispose()
{
    if(isResourceLoaded)
    {
        glDeleteTextures(1, &glId);
        isResourceLoaded = false;
    }
}


void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, glId);
}


void Texture::SetClamped(bool clamped)
{
	Bind();
	
	if(clamped)
	{
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	}
	else
	{
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
}
	

void Texture::Enable(bool enableTextures)
{
	if(enableTextures)
	{
		glEnable(GL_TEXTURE_2D);
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}
}


std::string Texture::ResourceType() {
	return "texture";
}
        
}
