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


Texture::Texture()
{
    glId = 0;
    width = 0;
    height = 0;
    resourceType = resource::Texture;
}


Texture::Texture(std::string filename)
{
    resourceType = resource::Texture;

    glId = 0;
    width = 0;
    height = 0;

    if(! Load(filename) )
    {
        throw LAVISH_EXCEPTION("Failed to load texture");
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


bool Texture::Load(std::string filename)
{
    //load the image from a file via sdl_img
    SDL_Surface* Surface = IMG_Load(filename.c_str());

    if(Surface == NULL)
    {
        std::cout << "Failed to load the image: " << filename << ", Error: " << SDL_GetError() << std::endl;
        return false;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT,4);

    glGenTextures(1,&glId);
    glBindTexture(GL_TEXTURE_2D, glId);
	
	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, true);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_PixelFormat *fmt = Surface->format;

    //setup all the information
    width = (unsigned int)Surface->w;
    height = (unsigned int)Surface->h;

	
	GLint imageFormat = GL_RGBA;
	GLint imageType	= GL_UNSIGNED_BYTE;
	GLint internalFormat = GL_RGBA8;
	
	switch (Surface->format->BitsPerPixel)
	{
		case 32: 
			imageFormat = GL_RGBA; 
			imageType = GL_UNSIGNED_BYTE;
			internalFormat = GL_RGBA8; 
			break;
		case 24: 
			imageFormat = GL_RGB; 
			imageType = GL_UNSIGNED_BYTE;
			internalFormat = GL_RGB8;
			break;
		case 16: 
			imageFormat = GL_RGBA; 
			imageType = GL_UNSIGNED_SHORT_5_5_5_1;
			internalFormat = GL_RGB5_A1; 
			break;
	}
	
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, imageFormat, imageType, Surface->pixels);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, internalFormat, width, height, imageFormat, imageType, Surface->pixels);
	

    //free the image
    SDL_FreeSurface(Surface);

    resourceName = filename;
    isResourceLoaded = true;
    
    return true;
}

void Texture::Dispose()
{
    if(isResourceLoaded)
    {
        glDeleteTextures(1, &glId);
        isResourceLoaded = false;
    }
}

bool Texture::Reload()
{
    Dispose();

    return Load(resourceName);
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

        
}
