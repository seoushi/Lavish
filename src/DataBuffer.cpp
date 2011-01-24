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

#include "DataBuffer.hpp"

#include <string.h>
#include <malloc.h>
#include <sstream>


namespace lavish
{


DataBuffer::DataBuffer()
{
    _buffer = NULL;
    _bufferSize = 0;
    _maxBufferSize = 0;
    _bufferPosition = 0;
}

DataBuffer::DataBuffer(char* data, size_t size)
{
    _buffer = NULL;
    _bufferPosition = 0;
    _bufferSize = 0;
    _maxBufferSize = 0;

    write(data, size);
}


DataBuffer::DataBuffer(DataBuffer& buf)
{
    _buffer = NULL;
    _bufferPosition = 0;
    _bufferSize = 0;
    _maxBufferSize = 0;

    write(buf.data(), buf.size());
}


DataBuffer::~DataBuffer()
{
    free(_buffer);
}


void DataBuffer::clear()
{
    resize(0);
}


size_t DataBuffer::position()
{
    return _bufferPosition;
}


void DataBuffer::resize(size_t newSize)
{
    if(newSize == 0)
    {
        _bufferSize = 0;
        _bufferPosition = 0;
    }

    // if the buffer doesn't exist make it
    if(!_buffer)
    {
        _buffer = (char*)malloc(newSize);
    }
    else // resize the buffer
    {
        _buffer = (char*)realloc(_buffer, newSize);
    }

    // if the new size is smaller
    if(newSize < _maxBufferSize)
    {
        _bufferPosition = 0;
    }


    // remeber how big it is
    _maxBufferSize = newSize;
}


void DataBuffer::rewind()
{
    _bufferPosition = 0;
}


void DataBuffer::seek(size_t bytes)
{
    _bufferPosition += bytes;

    if(_bufferPosition < 0)
    {
        _bufferPosition = 0;
    }
    if(_bufferPosition >= _maxBufferSize)
    {
        _bufferPosition = _maxBufferSize;
    }
}


size_t DataBuffer::spaceLeft()
{
    return _maxBufferSize - _bufferPosition;
}


size_t DataBuffer::size()
{
    return _bufferSize;
}


void DataBuffer::setSize(size_t size)
{
    if(size <= _maxBufferSize)
    {
        _bufferSize = size;
    }
}


size_t DataBuffer::allocatedSize()
{
    return _maxBufferSize;
}


char* DataBuffer::data()
{
    return _buffer;
}


///
/// Read functions
///

// returns a pointer to the next element
char* DataBuffer::read(size_t size)
{
    if(_buffer && (size <= spaceLeft()))
    {
        char* dat = (_buffer + _bufferPosition);
        seek(size);

        return dat;
    }

    return NULL;
}

DataBuffer& DataBuffer::operator >>(short& val)
{
    char* data = read(sizeof(val));
    val = data ? *((short*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(char& val)
{
    char* data = read(sizeof(val));
    val = data ? *((char*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(int& val)
{
    char* data = read(sizeof(val));
    val = data ? *((int*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(long long& val)
{
    char* data = read(sizeof(val));
    val = data ? *((long long*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(unsigned short& val)
{
    char* data = read(sizeof(val));
    val = data ? *((unsigned short*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(unsigned char& val)
{
    char* data = read(sizeof(val));
    val = data ? *((unsigned char*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(unsigned int& val)
{
    char* data = read(sizeof(val));
    val = data ? *((unsigned int*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(unsigned long long& val)
{
    char* data = read(sizeof(val));
    val = data ? *((unsigned long long*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(float& val)
{
    char* data = read(sizeof(val));
    val = data ? *((float*)data) : 0;
    return *this;
}


DataBuffer& DataBuffer::operator >>(double& val)
{
    char* data = read(sizeof(val));
    val = data ? *((double*)data) : 0;
    return *this;
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
        val = std::string("INVALID STRING");
    }
    else
    {
        val = ss.str();
    }
    
    return *this;
}


///
/// write functions
///


void DataBuffer::write(char* dataP, size_t length)
{
    // no buffer? buffer not big enough? resize it
    if(spaceLeft() < length)
    {
        resize(_maxBufferSize - spaceLeft() + length);
    }

    memcpy(_buffer + _bufferPosition, dataP, length);
    _bufferSize += length;

    seek(length);
}


DataBuffer& DataBuffer::operator <<(const short& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


DataBuffer& DataBuffer::operator <<(const char& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


DataBuffer& DataBuffer::operator <<(const int& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


DataBuffer& DataBuffer::operator <<(const long long& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


DataBuffer& DataBuffer::operator <<(const unsigned short& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


DataBuffer& DataBuffer::operator <<(const unsigned char& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


DataBuffer& DataBuffer::operator <<(const unsigned int& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


DataBuffer& DataBuffer::operator <<(const unsigned long long& val)
{
    write((char*)&val, sizeof(val));
    return *this;
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


DataBuffer& DataBuffer::operator <<(const float& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


DataBuffer& DataBuffer::operator <<(const double& val)
{
    write((char*)&val, sizeof(val));
    return *this;
}


} /* namespace lavish */
