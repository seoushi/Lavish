/* 
 * File:   settings.cpp
 * 
 * Copyright © 2011, Sean Chapel
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "settings.hpp"


namespace lavish
{


Settings::Settings()
{
}


Settings::~Settings()
{
}


bool Settings::create(uint32 id, std::string name)
{
    // check if the setting exists
    if(_settings.find(id) != _settings.end())
    {
        return false;
    }

    // add it
    _settings[id] = any();
    _nameLookup[id] = name;
    _idLookup[name] = id;

    return true;
}


bool Settings::set(uint32 id, any value)
{
    auto itr = _settings.find(id);

    // check if the setting exists
    if(itr != _settings.end())
    {
        itr->second = value;
        return true;
    }

    return false;
}


bool Settings::set(std::string name, any value)
{
    auto itr = _idLookup.find(name);

    // check if the name exists
    if(itr != _idLookup.end())
    {
        return set(itr->second, value);
    }
}


any Settings::get(uint32 id)
{
    auto itr = _settings.find(id);

    // check if the setting exists
    if(itr != _settings.end())
    {
        return itr->second;
    }

    return boost::any();
}


any Settings::get(std::string name)
{
    auto itr = _idLookup.find(name);

    // check if the name exists
    if(itr != _idLookup.end())
    {
        return get(itr->second);
    }

    return any();
}


std::string Settings::name(uint32 id)
{
    auto itr = _nameLookup.find(id);

    // check if the setting exists
    if(itr != _nameLookup.end())
    {
        return itr->second;
    }

    return "";
}


} /* lavish namespace */
