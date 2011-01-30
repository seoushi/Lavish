/* 
 * File:   fileStream.cpp
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

#include "fileStream.hpp"
#include "logger.hpp"

namespace lavish
{


FileStream::FileStream(PHYSFS_file* file, file::Mode mode)
    : _file(file), _mode(mode)
{
}


FileStream::~FileStream()
{
    PHYSFS_close(_file);
}


int64 FileStream::read(void* buffer, uint32 size)
{
    if(_mode != file::Read)
    {
        WARN("File is not open for reading, this will most likely fail.");
    }

    int64 result = PHYSFS_read(_file, buffer, 1, size);

    if(result == -1)
    {
        ERROR(PHYSFS_getLastError());
    }

    return result;
}


int64 FileStream::write(void* buffer, uint32 size)
{
    if((_mode != file::Write) || (_mode != file::Append))
    {
        WARN("File is not open for writing, this will most likely fail.");
    }

    int64 result = PHYSFS_write(_file, buffer, 1, size);

    if(result == -1)
    {
        ERROR(PHYSFS_getLastError());
    }

    return result;
}


bool FileStream::seek(int64 amount)
{
    if(!PHYSFS_seek(_file, amount))
    {
        ERROR(PHYSFS_getLastError());
        return false;
    }

    return true;
}


int64 FileStream::position()
{
    int64 result = PHYSFS_tell(_file);

    if(result == -1)
    {
        ERROR(PHYSFS_getLastError());
    }

    return result;
}


bool FileStream::eof()
{
    return PHYSFS_eof(_file) == 1;
}


int64 FileStream::length()
{
    return PHYSFS_fileLength(_file);
}



} /* lavish namespace */
