/* 
 * File:   textureResourceLoader.cpp
 * Author: Sean Chapel
 *
 * Created on Sept 26, 2011
 * Copyright 2011 Seoushi Games. All rights reserved.
 */

#include <memory>

#include <lavish/resource/textureResourceLoader.hpp>
#include <lavish/graphics/texture.hpp>


namespace lavish
{
	
	TextureResourceLoader::TextureResourceLoader() {
	}

	TextureResourceLoader::~TextureResourceLoader(){
	}

	std::string TextureResourceLoader::Type(){
		return "texture";
	}

	std::shared_ptr<Resource> TextureResourceLoader::Load(TiXmlElement* element){

		unsigned int glId;
		unsigned int width;
		unsigned int height;


		//load the image from a file via sdl_img
		SDL_Surface* Surface = IMG_Load( element->Attribute("file") );

		if(Surface == NULL)
		{
			std::cout << "Error: " << SDL_GetError() << std::endl;
			return NULL;
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
	

		//free the image
		SDL_FreeSurface(Surface);

		
		return std::make_shared<Texture>(glId, width, height);
	}

}
