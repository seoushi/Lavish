/* 
 * File:   Settings.cpp
 * Author: sean
 * 
 * Created on January 24, 2011, 5:36 PM
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
