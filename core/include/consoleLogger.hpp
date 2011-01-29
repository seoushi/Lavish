/* 
 * File:   consoleLogger.hpp
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

#ifndef CONSOLE_LOGGER_HPP
#define	CONSOLE_LOGGER_HPP

#include "logger.hpp"

namespace lavish
{


/**
 * A LoggerDelegate for logging to the console
 * warnings and info goto stdout and errors goto stderr
 */
class ConsoleLogger : LoggerDelegate
{
    public:

        /**
         * Default Constructor
         */
        ConsoleLogger();

        /**
         * Default Destructor
         */
        virtual ~ConsoleLogger();

        /**
         * Logging delegate function
         * @param level the level of loggering (warning, info, error)
         * @param function the function the log was called from
         * @param fileName the file name log was called from
         * @param line the line number the log was called from
         * @param message the message to lo
         */
        virtual void log(log::Level level, const std::string& function,
            const std::string& fileName, unsigned int line,
            const std::string& message);
};


} /* lavish namespace */

#endif	/* LOGGER_HPP */
