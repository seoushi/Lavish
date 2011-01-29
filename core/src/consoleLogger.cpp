/* 
 * File:   consoleLogger.cpp
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

#include <iostream>
//#include <stdlib.h>
#include <time.h>

#include "consoleLogger.hpp"


namespace lavish
{



ConsoleLogger::ConsoleLogger()
{
}


ConsoleLogger::~ConsoleLogger()
{
}


void ConsoleLogger::log(log::Level level, const std::string& function,
    const std::string& fileName, unsigned int line,
    const std::string& message)
{

    // Make the date/time into a string
    time_t now;
    tm* localTime = localtime(&now);
    
    char time[20];
    
    sprintf(time, "%04d-%02d-%02d %02d:%02d:%02d",
	localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
	localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    // log errors to cerr
    if(level == log::Error)
    {
        std::cerr << "[Error]  in " << fileName << ":" << line
                << " in function " << function << " : " << message << std::endl;

        return;
    }

    // add tag for warnings
    if(level == log::Warning)
    {
        std::cout << "[Warning]  in ";
    }

    // log the information
    std::cout << fileName << ":" << line << " in function " << function
            << " : " << message << std::endl;
}



} /* lavish namespace */
