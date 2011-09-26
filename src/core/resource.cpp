/* 
 * File:   resource.cpp
 * Author: Sean Chapel
 * 
 * Created on May 30, 2009, 12:33 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <lavish/core/resource.hpp>


namespace lavish
{


Resource::Resource()
{
    resourceName = "";
    isResourceLoaded = false;
}


Resource::~Resource()
{
}


std::string Resource::ResourceName()
{
    return resourceName;
}


bool Resource::IsLoaded()
{
    return isResourceLoaded;
}


} /* lavish */


