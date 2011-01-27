/* 
 * File:   Logger.cpp
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

#include <list>

#include "logger.hpp"


namespace lavish
{

    
Logger::Logger()
{
}


Logger::~Logger()
{
}


std::shared_ptr<Logger> Logger::shared()
{
    static std::shared_ptr<Logger> instance;

    // no instance? create one
    if(instance.get() == NULL)
    {
        instance = std::shared_ptr<Logger>(new Logger());
    }

    return instance;
}


void Logger::log(log::Level level, const std::string& function,
            const std::string& fileName, unsigned int line,
            const std::string& message)
{
    for(auto itr = _delegates.begin(); itr != _delegates.end(); itr++)
    {
        (*itr)->log(level, function, fileName, line, message);
    }
}


void Logger::addDelegate(std::shared_ptr<LoggerDelegate> d)
{
    _delegates.push_back(d);
}


void Logger::removeDelegate(std::shared_ptr<LoggerDelegate> d)
{
    for(auto itr = _delegates.begin(); itr != _delegates.end(); itr++)
    {
        // check the actual pointer not the shared_ptr
        if(itr->get() == d.get())
        {
           _delegates.erase(itr);
           return;
        }
    }
}


} /* lavish namespace */
