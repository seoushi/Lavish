/* 
 * File:   Settings.hpp
 * Author: Sean Chapel
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

#ifndef SETTINGS_HPP
#define	SETTINGS_HPP


#include <map>
#include <string>

#include "types.hpp"


namespace lavish
{


class Settings
{
    public:
        Settings();
    
        virtual ~Settings();

        /**
         * Creates a new setting with a name and id
         * @param id the id of the setting
         * @param name the name of the setting
         * @return false if the setting already exists
         */
        bool create(uint32 id, std::string name);

        /**
         * Sets a settings value by id
         * @param id the id of the setting
         * @param value the value to set to the setting
         * @return false is the setting doesn't exist
         */
        bool set(uint32 id, any value);

        /**
         * Sets a settings value by name
         * @param name the name of the setting
         * @param value the value to set to the setting
         * @return false is the setting doesn't exist
         */
        bool set(std::string name, any value);

        /**
         * Gets a setting's value by id
         * @param id the id of the setting
         * @return the value of the setting
         */
        any get(uint32 id);

        /**
         * Gets a setting's value by name
         * @param name the name of the setting
         * @return the value of the setting
         */
        any get(std::string name);

        /**
         * Gets the name as a string of a setting
         * @param id the id of the setting
         * @return the name of the setting,
         *    empty string if the setting doesn't exist
         */
        std::string name(uint32 id);


    protected:
        
        /// Holds the linking between: id -> value
        std::map<uint32, any> _settings;

        /// Holds the linking between: name -> id
        std::map<std::string, uint32> _idLookup;

        /// Holds the linking between: id -> name
        std::map<uint32, std::string> _nameLookup;
};


} /* lavish namespace */

#endif	/* SETTINGS_HPP */

