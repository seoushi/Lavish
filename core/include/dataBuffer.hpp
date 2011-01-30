/* 
 * File:   DataBuffer.hpp
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

#ifndef DATABUFFER_HPP
#define	DATABUFFER_HPP

#include <string>
#include <memory>

namespace lavish
{


/**
 * The Data Buffer class holds a chunk of memory to read and write to. Data
 * Buffers will automatically resize when written to when needed.
 */
class DataBuffer
{
    public:

        /**
         * Default constructor
         */
        DataBuffer();

        /**
         * Constructor with data intialization
         * This copies the data passed in and sets the position to 0
         * @param data the data to copy to the buffer
         * @param size the size of the data
         */
        DataBuffer(char* data, size_t size);

        /**
         * Constructor from another DataBuffer
         * This copies the data passed in and sets the position to 0
         * @param buffer the DataBuffer to copy
         */
        DataBuffer(DataBuffer& buffer);

        /**
         * Default destructor
         */
        ~DataBuffer();

        /**
         * Clears all the data from the buffer
         */
        void clear();

        /**
         * Gets the current position in the buffer
         * @return the position in the buffer
         */
        size_t position();

        /**
         * Resizes the data buffer to a given size.
         * if the newSize is smaller than the previous size the buffer position
         * is set back to the begining
         * @param newSize the new size for the buffer
         */
        void resize(size_t newSize);

        /**
         * Sets the current data pointer to the begining of the buffer
         */
        void rewind();

        /**
         * moves the position in the buffer forward by an amount
         * seek will no go past the end of a buffer or before the begining
         * @param bytes the amount to move forward in the buffer
         */
        void seek(size_t bytes);

        /**
         * Gets the size of the data buffer currently in use
         * @return the buffers size
         */
        size_t size();

        /**
         * Sets the size of the data buffer currently in use
         * @param size the new size
         */
        void setSize(size_t size);

        /**
         * Gets the max size the data buffer can hold
         * @return the buffer's max size
         */
        size_t allocatedSize();

        /**
         * Gets the space left for writing in the buffer
         * @return the space left in the buffer
         */
        size_t spaceLeft();

        /**
         * Gets a pointer to begining of the data
         * @return pointer to the begining of the data
         */
        std::shared_ptr<char> data();

        /**
         * Gets a chunk of memory from the buffer
         * @param size the amount to read
         * @return the data read
         */
        char* read(size_t size);

        /**
         * Reads an std::string from the buffer
         * @param s the string to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(std::string& s);

        /**
         * Reads a type from the buffer
         * @param value the value to read into
         * @return a reference to the data buffer
         */
        template <typename T>
        DataBuffer& operator >>(T& value)
        {
            char* data = read(sizeof(T));
            value = data ? *((T*)data) : 0;
            return *this;
        }

        /**
         * Writes a chunk of memory to the buffer
         * @param data the data to write to the buffer
         * @param length the length of the data to write
         */
        void write(char* data, size_t length);

        
        /**
         * Writes a std::string to the buffer
         * @param s the string to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const std::string& s);

        /**
         * Writes a value to the buffer
         * @param value the value to write
         * @return a reference to the DataBuffer
         */
        template <typename T>
        DataBuffer& operator <<(const T& value)
        {
            write((char*)&value, sizeof(T));
            return *this;
        }

    private:

        std::shared_ptr<char> _buffer; /**< pointer to the data buffer  */
        
        size_t _size;      /**< the amount currently used in the buffer */
        size_t _maxSize;   /**< the size of the allocated buffer        */
        size_t _position;  /**< the current position in the buffer      */
};


} /* lavish namespace */


#endif	/* DATABUFFER_HPP */
