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

#include <sstream>

#include "fileSystem.hpp"
#include "logger.hpp"

#include <physfs.h>


namespace lavish
{


FileSystem::FileSystem()
{
}


FileSystem::~FileSystem()
{
    if(PHYSFS_isInit() && !PHYSFS_deinit())
    {
        ERROR(PHYSFS_getLastError());
    }
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
    _rootPath = rootPath;
    
    // only init phyfs if it hasn't already
    if( !PHYSFS_isInit() )
    {
        if(!PHYSFS_init(rootPath.c_str()))
        {
            ERROR(PHYSFS_getLastError());
            return false;
        }

        PHYSFS_setSaneConfig("", "", NULL, 0, 0);
    }

    return true;
}


void FileSystem::addPath(std::string path)
{
    std::stringstream ss;
    ss << _rootPath << "/" << path;

    PHYSFS_addToSearchPath(ss.str().c_str(), 1);
}


void FileSystem::removePath(std::string path)
{
    std::stringstream ss;
    ss << _rootPath << "/" << path;

    PHYSFS_removeFromSearchPath(ss.str().c_str());
}


std::list<std::string> FileSystem::searchPaths()
{
    std::list<std::string> paths;

    char** sps = PHYSFS_getSearchPath();

    if(!sps)
    {
        ERROR(PHYSFS_getLastError());
        return paths;
    }

    int dirCount = 0;
    char** itr;
    
    for(itr = sps; *itr != NULL; itr++, dirCount++)
    {
        paths.push_back(std::string(*itr));
    }
   
    PHYSFS_freeList(sps);

    return paths;
}


bool FileSystem::makeDir(std::string dir)
{
     if(!PHYSFS_mkdir(dir.c_str()))
     {
         ERROR(PHYSFS_getLastError());
         return false;
     }

     return true;
}


void FileSystem::setWriteDir(std::string dir)
{
    PHYSFS_setWriteDir(dir.c_str());
}


bool FileSystem::doesFileExist(std::string fileName)
{
    return PHYSFS_exists(fileName.c_str());
}


std::shared_ptr<FileStream> FileSystem::open(std::string fileName,
                                             file::Mode mode)
{
    std::shared_ptr<FileStream> filePtr;
    PHYSFS_file* file = NULL;

    switch(mode)
    {
        case file::Append:
            file = PHYSFS_openAppend(fileName.c_str());
            break;
        case file::Read:
            file = PHYSFS_openRead(fileName.c_str());
            break;
        case file::Write:
            file = PHYSFS_openWrite(fileName.c_str());
            break;
        default:
            WARN("unrecognized file mode");
            return filePtr;
            break;
    }

    if(!file)
    {
        WARN(PHYSFS_getLastError());
        return filePtr;
    }

    return std::shared_ptr<FileStream>(new FileStream(file, mode));
}




} /* lavish namespace */

