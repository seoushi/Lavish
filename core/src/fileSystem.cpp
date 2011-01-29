/* 
 * File:   FileSystem.cpp
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

#include "fileSystem.hpp"
#include "physfs.h"


namespace lavish
{


FileSystem::FileSystem()
{
}


FileSystem::~FileSystem()
{
}


std::shared_ptr<FileSystem> FileSystem::shared()
{
    static std::shared_ptr<FileSystem> instance;

    // no instance? create one
    if(instance.get() == NULL)
    {
        instance = std::shared_ptr<FileSystem>(new FileSystem());
    }

    return instance;
}


bool FileSystem::init(std::string rootPath)
{
    // only init phyfs if it hasn't already
    if( !PHYSFS_isInit() )
    {
        PHYSFS_init(rootPath.c_str());
        PHYSFS_setSaneConfig("", "", NULL, 0, 0);
    }
}


}
