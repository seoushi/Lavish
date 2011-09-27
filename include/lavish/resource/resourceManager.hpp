/* 
 * File:   resourceManager.hpp
 * Author: Sean Chapel
 *
 * Created on Sept 26, 2011
 * Copyright 2011 Seoushi Games. All rights reserved.
 */

#ifndef _RESOURCE_MANAGER_HPP
#define	_RESOURCE_MANAGER_HPP

#include <string>
#include <map>
#include <memory>

#include <lavish/core/resource.hpp>
#include <lavish/resource/tinyxml.h>

namespace lavish
{
	class ResourceLoader {

		public:
			ResourceLoader(){};

			virtual ~ResourceLoader(){};

			virtual std::string Type() = 0;

			virtual std::shared_ptr<Resource> Load(TiXmlElement* element) = 0;
	};


	class ResourceManager {

		public:

			ResourceManager();

			~ResourceManager();

			bool Load(std::string resourceFile);

			void Unload(std::string resourceName);

			void Clear();

			void AddResourceLoader(std::shared_ptr<ResourceLoader> resourceLoader);

			template <class T>
			T Get(std::string resourceName) {

				if(resources.find(resourceName) != NULL) {
					return (T)resources[resourceName];
				}

				return NULL;
			}

		private:

			std::map<std::string, std::shared_ptr<Resource>> resources;
			std::map<std::string, std::shared_ptr<ResourceLoader>> resourceLoaders;

	};
}

#endif