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

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    SDL_PixelFormat *fmt = Surface->format;

    //setup all the information
    width = (unsigned int)Surface->w;
    height = (unsigned int)Surface->h;

    //if there is alpha
    if (fmt->Amask)
    {
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, GL_RGBA, GL_UNSIGNED_BYTE, Surface->pixels);
    }
    else // no alpha
    {
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, Surface->pixels);
    }

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

        
}
