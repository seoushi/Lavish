/* 
 * File:   fileSystem.hpp
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

#ifndef FILESYSTEM_HPP
#define	FILESYSTEM_HPP

#include <memory>
#include <string>
#include <list>

namespace lavish
{


class FileSystem
{
    public:

        /**
         * Default Constructor
         */
        FileSystem();

        /**
         * Default Destructor
         */
        virtual ~FileSystem();

        /**
         * Gets the shared instance of the file system
         * @return the shared instance of the file system
         */
        static std::shared_ptr<FileSystem> shared();

        
        /**
         * Initalizes the file system
         * @param rootPath the root path to the executable
         * @return true if the file system was initalized
         */
        bool init(std::string rootPath);

        /**
         * Adds a path to search for files in (this includes pack files).
         * the path passed in will automatically have the rootPath appended to
         * the front.
         * @param the path to add
         */
        void addPath(std::string path);

        /**
         * Removes a path to search for files in (this includes pack files).
         * the path passed in will automatically have the rootPath appended to
         * the front.
         * @param the path to remove
         */
        void removePath(std::string path);

        /**
         * Gets a list of the search paths
         * @return a list of the search paths
         */
        std::list<std::string> searchPaths();

        /**
         * Creates a directory
         * @param the directory to make
         * @return true if the directory was made
         */
        bool makeDir(std::string dir);


        /*
        FileStream write(std::string file);
        FileStream append(std::string file);
        FileStream read(std::string file);
         */

    private:

        std::string _rootPath; /**< the root path of the application */
};


} /* lavish namespace */

#endif	/* FILESYSTEM_HPP */

