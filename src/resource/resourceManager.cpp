/* 
 * File:   resourceManager.cpp
 * Author: Sean Chapel
 *
 * Created on Sept 26, 2011
 * Copyright 2011 Seoushi Games. All rights reserved.
 */

#include <iostream>

#include <lavish/resource/resourceManager.hpp>


namespace lavish
{


ResourceManager::ResourceManager() {
}

ResourceManager::~ResourceManager(){
}

bool ResourceManager::Load(std::string resourceFile){

	// TODO: implement
	TiXmlDocument doc(resourceFile.c_str());
	
	if(!doc.LoadFile()){
		return false;
	}

	auto node = doc.FirstChild("resources");

	if(!node){
		return false;
	}

	node = node->FirstChild();

	while(node != NULL){

		std::string type = node->Value();
		std::string name = node->ToElement()->Attribute("name");

		if(resourceLoaders.find(type) != resourceLoaders.end()){
			
			auto result = resourceLoaders[type]->Load(node->ToElement());

			if(result == NULL){
				std::cout << "Failed to load resource " << name << std::endl;
			} else {
				resources[name] = result;
			}
		} 
		else {
			std::cout << "No such resource loader for " << name << " of type " << type << std::endl;
		}

		node = node->NextSibling();
	}

	return true;
}

void ResourceManager::Unload(std::string resourceName){
	resources.erase(resources.find(resourceName));
}

void ResourceManager::Clear() {
	resources.clear();
}

void ResourceManager::AddResourceLoader(std::shared_ptr<ResourceLoader> resourceLoader){
	resourceLoaders[resourceLoader->Type()] = resourceLoader;
}


}
