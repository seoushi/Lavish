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

#include <stddef.h>
#include <string>


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
        char* data();


    /***************************************************************************
     * READ FUNCTIONS
     *
     * All read functions move the data pointer forward by the amount read
     **************************************************************************/


        /**
         * Gets a chunk of memory from the buffer
         * @param size the amount to read
         * @return the data read
         */
        char* read(size_t size);

        /**
         * Reads a short from the buffer
         * @param s the short to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(short& s);

        /**
         * Reads a char from the buffer
         * @param c the char to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(char& s);

        /**
         * Reads an int from the buffer
         * @param i the int to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(int& i);

        /**
         * Reads a long long from the buffer
         * @param ll the long long to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(long long& ll);

        /**
         * Reads a unsigned short from the buffer
         * @param us the unsigned short to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(unsigned short& us);

        /**
         * Reads a unsigned char from the buffer
         * @param uc the unsigned char to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(unsigned char& uc);

        /**
         * Reads a unsigned int from the buffer
         * @param ui the unsigned int to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(unsigned int& ui);
        
        /**
         * Reads a unsigned long long from the buffer
         * @param ull the unsigned long long to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(unsigned long long& ull);
        

        /**
         * Reads an float from the buffer
         * @param f the float to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(float& f);

        /**
         * Reads an double from the buffer
         * @param d the double to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(double& d);

        /**
         * Reads an std::string from the buffer
         * @param s the int to read into
         * @return a reference to the data buffer
         */
        DataBuffer& operator >>(std::string& s);



    /***************************************************************************
     * WRITE FUNCTIONS
     *
     * All write functions will increase the size of the buffer as needed
     **************************************************************************/


        /**
         * Writes a chunk of memory to the buffer
         * @param data the data to write to the buffer
         * @param length the length of the data to write
         */
        void write(char* data, size_t length);

        /**
         * Writes a short to the buffer
         * @param s the short to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const short& s);

        /**
         * Writes a char to the buffer
         * @param c the char to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const char& c);

        /**
         * Writes an int to the buffer
         * @param i the int to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const int& i);

        /**
         * Writes a long long to the buffer
         * @param ll the long long to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const long long& ll);

        /**
         * Writes a unsigned short to the buffer
         * @param us the unsigned short to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const unsigned short& us);

        /**
         * Writes a unsigned char to the buffer
         * @param uc the unsigned char to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const unsigned char& uc);

        /**
         * Writes a unsigned int to the buffer
         * @param ui the unsigned int to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const unsigned int& ui);

        /**
         * Writes a unsigned long long to the buffer
         * @param ull the unsigned long long to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const unsigned long long& ull);

        /**
         * Writes a std::string to the buffer
         * @param s the string to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const std::string& s);

        /**
         * Writes a float to the buffer
         * @param f the float to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const float& f);

        /**
         * Writes a double to the buffer
         * @param d the double to write
         * @return a reference to the DataBuffer
         */
        DataBuffer& operator <<(const double& d);

    private:

        char* _buffer;           /**< pointer to the data buffer              */
        size_t _bufferSize;      /**< the amount currently used in the buffer */
        size_t _maxBufferSize;   /**< the size of the allocated buffer        */
        size_t _bufferPosition;  /**< the current position in the buffer      */
};

} /* namespace lavish */

#endif	/* DATABUFFER_HPP */

