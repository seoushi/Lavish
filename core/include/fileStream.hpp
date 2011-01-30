/* 
 * File:   fileStream.hpp
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

#ifndef FILESTREAM_HPP
#define	FILESTREAM_HPP

#include "physfs.h"
#include "types.hpp"

namespace lavish
{


namespace file
{
    /// The mode for file operations on a file
    enum Mode
    {
        Read,   /**< only read the contents      */
        Write,  /**< overwrite the existing file */
        Append, /**< add to an existing file     */
    };
}

class FileStream
{
    public:

        /**
         * Default Constructor
         */
        FileStream(PHYSFS_file* file, file::Mode mode);

        /**
         * Default Destructor
         */
        virtual ~FileStream();

        /**
         * Reads data from the file into the buffer
         * @param buffer the buffer to write into
         * @param size the amount to read
         * @return the number of bytes read, -1 for failure
         */
        int64 read(void* buffer, uint32 size);

        /**
         * Writes data from a buffer into the file
         * @param buffer the buffer to write from
         * @param size the amount to write
         * @return the number of bytes written, -1 for failure
         */
        int64 write(void* buffer, uint32 size);
        
        /**
         * Seek a certain amount in the file
         * @param amount the amount to seek
         * @return True on success
         */
        bool seek(int64 amount);

        /**
         * Tells the current position in the file
         * @return the position in the file, -1 on failure
         */
        int64 position();

        /**
         * Tells if the position is at the end of the file
         * @return true if the position is at the end of the file
         */
        bool eof();

        /**
         * Gets the length of the file
         * @return the length of the file
         */
        int64 length();

    private:

        file::Mode _mode;   /**< the mode of the file */
        PHYSFS_file* _file; /**< pointer to the physfs representation of the
                             *   file */
};


} /* lavish namespace */

#endif	/* FILESTREAM_HPP */

