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
         * Returns the resource's type
         * @return the type of the resource
         */
        virtual std::string ResourceType() = 0;

        
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

        std::string     resourceName;
        bool            isResourceLoaded;

};


} /* lavish */

#endif	/* _RESOURCE_HPP */

