/* 
 * File:   exceptions.cpp
 * Author: Sean Chapel
 *
 * Created on Jan 08, 2010, 5:30 PM
 * Copyright 2010 Seoushi Games. All rights reserved.
 *
 */

#include <lavish/core/exception.hpp>

namespace lavish
{
	Exception::Exception()
	{
		message = filename = function = "";
		line = 0;
	}

	Exception::Exception(const std::string& message)
	{
		this->message = message;
		filename = function = "";
		line = 0;
	}


	Exception::Exception(std::string message, std::string function, std::string filename, unsigned int line)
	{
		this->message = message;
		this->filename = filename;
		this->function = function;
		this->line = line;
	}

	
	std::string Exception::getFunction()
	{
		return filename;
	}

	
	std::string Exception::getMessage()
	{
		return message;
	}


	std::string Exception::getFilename()
	{
		return filename;
	}
	
	
	unsigned int Exception::getLine()
	{
		return line;
	}
	
} /* namespace lavish */


