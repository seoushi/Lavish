/* 
 * File:   DataBuffer.cpp
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

#include "dataBuffer.hpp"

#include <string.h>
#include <malloc.h>
#include <sstream>
#include "logger.hpp"


namespace lavish
{


DataBuffer::DataBuffer()
    : _size(0), _maxSize(0), _position(0)
{
    _buffer = std::shared_ptr<char>();
}


DataBuffer::DataBuffer(char* data, size_t size)
    : _size(0), _maxSize(0), _position(0)
{
    _buffer = std::shared_ptr<char>();
    write(data, size);
}


DataBuffer::DataBuffer(DataBuffer& buf)
    : _size(0), _maxSize(0), _position(0)
{
    _buffer = std::shared_ptr<char>();
    write(buf.data().get(), buf.size());
}


DataBuffer::~DataBuffer()
{
}


void DataBuffer::clear()
{
    resize(0);
}


size_t DataBuffer::position()
{
    return _position;
}


void DataBuffer::resize(size_t newSize)
{
    if(newSize == 0)
    {
        _size = 0;
        _position = 0;
    }

    // if the buffer doesn't exist make it
    if(_buffer.get() == NULL)
    {
        _buffer = std::shared_ptr<char>(new char(newSize));
    }
    else // resize the buffer
    {
        _buffer = std::shared_ptr<char>((char*)realloc(_buffer.get(), newSize));
    }

    // if the new size is smaller
    if(newSize < _maxSize)
    {
        _position = 0;
    }


    // remeber how big it is
    _maxSize = newSize;
}


void DataBuffer::rewind()
{
    _position = 0;
}


void DataBuffer::seek(size_t bytes)
{
    _position += bytes;

    if(_position < 0)
    {
        _position = 0;
    }
    if(_position >= _maxSize)
    {
        _position = _maxSize;
    }
}


size_t DataBuffer::spaceLeft()
{
    return _maxSize - _position;
}


size_t DataBuffer::size()
{
    return _size;
}


void DataBuffer::setSize(size_t size)
{
    if(size <= _maxSize)
    {
        _size = size;
    }
}


size_t DataBuffer::allocatedSize()
{
    return _maxSize;
}


std::shared_ptr<char> DataBuffer::data()
{
    return _buffer;
}


// returns a pointer to the next element
char* DataBuffer::read(size_t size)
{
    if((_buffer.get() != NULL) && (_size <= spaceLeft()))
    {
        char* data = (_buffer.get() + _position);
        seek(size);

        return data;
    }

    return NULL;
}


DataBuffer& DataBuffer::operator >>(std::string& val)
{
    std::stringstream ss;
    char c;

    for(;;)
    {
        (*this) >> c;

        if(c == 0)
        {
            break;
        }
        else
        {
            ss << c;
        }
    }

    if(ss.str().length() <= 0)
    {
        WARN("Read invalid string");
        val = std::string("INVALID STRING");
    }
    else
    {
        val = ss.str();
    }
    
    return *this;
}


void DataBuffer::write(char* data, size_t length)
{
    // no buffer? buffer not big enough? resize it
    if(spaceLeft() < length)
    {
        resize(_maxSize - spaceLeft() + length);
    }

    memcpy(_buffer.get() + _position, data, length);
    _size += length;

    seek(length);
}


DataBuffer& DataBuffer::operator <<(const std::string& val)
{
    for(std::string::const_iterator itr = val.begin(); itr != val.end(); itr++)
    {
        *this << (*itr);
    }
    *this << (char)0;
    
    return *this;
}


} /* lavish namespace */
