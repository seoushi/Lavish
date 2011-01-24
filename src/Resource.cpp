/* 
 * File:   resource.cpp
 * Author: Sean Chapel
 * 
 * Created on May 30, 2009, 12:33 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include "Resource.hpp"


namespace lavish
{


Resource::Resource()
{
    resourceType = resource::Unknown;
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


resource::Type Resource::ResourceType()
{
    return resourceType;
}


bool Resource::IsLoaded()
{
    return isResourceLoaded;
}


} /* lavish */


