/* 
 * File:   Logger.hpp
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

#ifndef LOGGER_HPP
#define	LOGGER_HPP

#include <memory>
#include <string>
#include <list>

namespace lavish
{


namespace log
{
    /// Levels of logging
    enum Level
    {
        Info,
        Warning,
        Error,
    };
}

class LoggerDelegate;

/**
 * The Logger class is a generic logger interface
 * The logger has delegates to handle where to log to (Console, File, Network..)
 */
class Logger
{
    public:

        /**
         * Default Constructor
         */
        Logger();

        /**
         * Default Destructor
         */
        virtual ~Logger();

        /**
         * Gets a shared instance of the logger
         * @return a shared Logger instance
         */
        static std::shared_ptr<Logger> shared();

        /**
         * Logs information, it's generally more useful to use the macros
         * defined than this function
         * @param level the level of loggering (warning, info, error)
         * @param function the function the log was called from
         * @param fileName the file name log was called from
         * @param line the line number the log was called from
         * @param message the message to log
         */
        void log(log::Level level, const std::string& function,
            const std::string& fileName, unsigned int line,
            const std::string& message);

        /**
         * Adds a delegate to log to
         * @param d the delegate to log to
         */
        void addDelegate(std::shared_ptr<LoggerDelegate> d);

        /**
         * Removes a delegate from the logger
         * @param d the delegate to remove
         */
        void removeDelegate(std::shared_ptr<LoggerDelegate> d);

    protected:

        ///delegates to log to
        std::list< std::shared_ptr<LoggerDelegate> > _delegates;
};


/**
 * The Logger Delegate class is a delegate for the Logger class to
 * handle logging
 */
class LoggerDelegate
{
    public:

        /**
         * Default Constructor
         */
        LoggerDelegate(){};

        /**
         * Default constructor that must be implemented
         */
        virtual ~LoggerDelegate() = 0;

        /**
         * Logging function that must be implemented
         * @param level the level of loggering (warning, info, error)
         * @param function the function the log was called from
         * @param fileName the file name log was called from
         * @param line the line number the log was called from
         * @param message the message to lo
         */
        virtual void log(log::Level level, const std::string& function,
            const std::string& fileName, unsigned int line,
            const std::string& message) = 0;
};


} /* lavish namespace */


/// Logs information to the shared Logging instance
#define LOG(message) lavish::Logger::shared()->log(lavish::log::Info, \
    __FUNCTION__, __FILE__, __LINE__, message)

/// Logs warnings to the shared Logging instance
#define WARN(message) lavish::Logger::shared()->log(lavish::log::Warning, \
    __FUNCTION__, __FILE__, __LINE__, message)

/// Logs errors to the shared Logging instance
#define ERROR(message) lavish::Logger::shared()->log(lavish::log::Error, \
    __FUNCTION__, __FILE__, __LINE__, message)


#endif	/* LOGGER_HPP */
