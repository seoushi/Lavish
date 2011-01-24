/* 
 * File:   Exception.hpp
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
 *
 */

#ifndef EXCEPTION_HPP
#define	EXCEPTION_HPP

#include <string>

#ifndef __FUNCTION__
#define __FUNCTION__ "?"
#endif


/**
 * a simple macro to throw an exception with all details
 */	
#define LAVISH_EXCEPTION(mess) lavish::Exception(mess,          \
                                                __FUNCTION__,   \
                                                __FILE__,       \
                                                __LINE__)

namespace lavish
{


class Exception
{
    public:

        /**
         * Constructor.
         */
        Exception();


        /**
         * Constructor.
         * @param the error message to throw
         */
        Exception(const std::string& message);


        /**
         * Constructor.
         * @param the error message to throw
         * @param the name of the function
         * @param the name of the file
         * @param the line number
         */
        Exception(std::string message, std::string function, std::string filename, unsigned int line);


        /**
         * Gets the function name
         * @return The function name
         */
        std::string function();


        /**
         * Gets the error message
         * @return The error message
         */
        std::string message();


        /**
         * Gets the filename
         * @return The filename
         */
        std::string filename();


        /**
         * Gets the line number
         * @return The line number
         */
        unsigned int line();

    protected:

        std::string _function;
        std::string _message;
        std::string _filename;
        unsigned int _line;
};

} /* namespace lavish */


#endif	/* EXCEPTION_HPP */

