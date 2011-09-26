/* 
 * File:   vertexBuffer.hpp
 * Author: Sean Chapel
 *
 * Created on May 30, 2009, 7:56 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _VERTEXBUFFER_HPP
#define	_VERTEXBUFFER_HPP

#include <vector>

#include <lavish/core/platform.hpp>
#include <lavish/graphics/vertexFormats.hpp>
#include <lavish/core/resource.hpp>
#include <lavish/common/types.hpp>

namespace lavish
{



/**
 * A vertex buffer object that stores a fixed size of elements
 */
template <class T>
class VertexBuffer : public Resource
{

    public:

        /**
         * A default constructor
         */
        VertexBuffer()
        {
        }

        /**
         * A constructor with the number of elements and thier types
         * @param numElements the number of elements to store
         * @param type the type of vertex buffer
         */
        VertexBuffer(unsigned int numElements)
        {
            SetSize(numElements);
        }


        /**
         * Default destructor
         */
        ~VertexBuffer()
        {
            Dispose();
        }

        /**
         * Sets the number of elements for the VBO
         * @param numElements the number of elements to store
         */
        void SetSize(unsigned int numElements)
        {
            buffer.clear();
            buffer.reserve(numElements);
        }

        /**
         * Adds an element
         * @param v the element to add
         */
        void AddElement(const T &element)
        {
            buffer.push_back(element);
        }

	
		/** Gets the number of elements in the buffer
		 * @return the number of elements
		 */
		uint NumElements()
		{
			return buffer.size();
		}


        /**
         * Generates the buffer for use
         */
        void Generate()
        {
            if(buffer.size() == 0)
            {
                return;
            }

            Dispose();

            glGenBuffers( 1, &glId );
            glBindBuffer( GL_ARRAY_BUFFER_ARB, glId );

            glBufferData(GL_ARRAY_BUFFER_ARB, buffer.size() * sizeof(buffer[0]), &buffer[0], GL_STATIC_DRAW_ARB);
            
            glUnmapBuffer( GL_ARRAY_BUFFER_ARB );
            glBindBuffer( GL_ARRAY_BUFFER_ARB, 0 );

            isResourceLoaded = true;
        }

        
        /**
         * binds the buffer for use
         */
        void Bind()
        {
            glBindBuffer(GL_ARRAY_BUFFER_ARB, glId);

            T::SetupDraw();
        }


        /**
         * Unbinds the buffer
         */
        void Unbind()
        {
            T::TeardownDraw();
        }


        /**
         * Implements the resource's dispose method
         */
        virtual void Dispose()
        {
            if(isResourceLoaded)
            {
                glDeleteBuffers(1, &glId);
                isResourceLoaded = false;
            }
        }

		virtual std::string ResourceType() {
			return "vertexBuffer";
		}

    private:

        uint glId;
        std::vector<T> buffer;
};


} /* lavish */


#endif	/* _VERTEXBUFFER_HPP */

