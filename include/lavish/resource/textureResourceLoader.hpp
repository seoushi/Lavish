/* 
 * File:   textureResourceLoader.hpp
 * Author: Sean Chapel
 *
 * Created on Sept 26, 2011
 * Copyright 2011 Seoushi Games. All rights reserved.
 */

#ifndef _TEXTURE_RESOURCE_LOADER_HPP
#define	_TEXTURE_RESOURCE_LOADER_HPP

#include <string>

#include <lavish/resource/resourceManager.hpp>
#include <lavish/resource/tinyxml.h>

namespace lavish
{
	class TextureResourceLoader : public ResourceLoader {

		public:
			TextureResourceLoader();

			virtual ~TextureResourceLoader();

			virtual std::string Type();

			virtual std::shared_ptr<Resource> Load(TiXmlElement* element);
	};

}

#endif