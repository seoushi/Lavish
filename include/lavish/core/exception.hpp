/* 
 * File:   exceptions.hpp
 * Author: Sean Chapel
 *
 * Created on Jan 08, 2010, 4:48 PM
 * Copyright 2010 Seoushi Games. All rights reserved.
 *
 */

#ifndef _EXCEPTION_HPP
#define	_EXCEPTION_HPP

#include <lavish/platform.hpp>

#ifndef __FUNCTION__
#define __FUNCTION__ "?"
#endif


/**
 * a simple macro to throw an exception with all details
 */	
#define LAVISH_EXCEPTION(mess) lavish::Exception(mess,	\	
									__FUNCTION__,		\
									__FILE__,           \
									__LINE__)

namespace lavish
{
	class LAVISH_DECLSPEC Exception
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
        std::string getFunction();

        
		/**
         * Gets the error message
         * @return The error message
         */
        std::string getMessage();

        
		/**
         * Gets the filename
         * @return The filename
         */
        std::string getFilename();

        
		/**
         * Gets the line number
         * @return The line number
         */
        unsigned int getLine();

    protected:

        std::string function;
        std::string message;
        std::string filename;
        unsigned int line;
    };

} /* namespace lavish */


#endif	/* _EXCEPTION_HPP */

