/* 
 * File:   resource.hpp
 * Author: Sean Chapel
 *
 * Created on May 30, 2009, 12:33 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _RESOURCE_HPP
#define	_RESOURCE_HPP

#include <string>
#include <lavish/core/platform.hpp>

namespace lavish
{


namespace resource
{
    /**
     * An enum of the types of resources
     */
    enum Type
    {
        Unknown,
        Texture,
        Sprite,
        VertexBuffer,
		Shader,
		Model,
        Custom
    };
} /* resource */



/**
 * An interface class to define what a resource is
 */
class Resource
{
    public:

        /**
         * A default constructor
         */
        Resource();


        /**
         * A virtual destructor
         */
        virtual ~Resource();


        /**
         * Returns the resource's name
         * @return the name of the resource
         */
        std::string ResourceName();


        /**
         * Returns the resource's type
         * @return the type of the resource
         */
        resource::Type ResourceType();

        
        /**
         * A virtual function that should release it's data
         */
        virtual void Dispose() = 0;


        /**
         * Returns is a resource is currently loaded
         * @return if the resource is loaded
         */
        bool IsLoaded();
        

    protected:

        resource::Type  resourceType;
        std::string     resourceName;
        bool            isResourceLoaded;

};


} /* lavish */

#endif	/* _RESOURCE_HPP */

