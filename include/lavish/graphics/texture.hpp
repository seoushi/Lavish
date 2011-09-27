/* 
 * File:   texture.hpp
 * Author: Sean Chapel
 *
 * Created on May 27, 2009, 3:11 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _TEXTURE_HPP
#define	_TEXTURE_HPP

#include <string>
#include <lavish/core/resource.hpp>
#include <lavish/core/platform.hpp>

namespace lavish
{

/**
 * A class that defines a texture
 */
class Texture : public Resource
{
    public:

        /**
         * Default constructor
         */
		Texture(unsigned int glId, unsigned int width, unsigned int height);

        
        /**
         * A default destructor
         */
        ~Texture();

        
        /**
         * gets the texture's width
         * @return texture width
         */
        unsigned int Width();


        /**
         * gets the texture's height
         * @return texture height
         */
        unsigned int Height();

        /**
         * Virtual function from the resource class
         */
        virtual void Dispose();


        /**
         * binds the texture for using in drawing
         */
        void Bind();
	
		/**
		 * Changes is a texture is clamped between 0.0 to 1.0 or if it repeats
		 * default is not clamped
		 * @param if the texture should clamp or not
		 */
		void SetClamped(bool clamped);
	
	
		/**
		 * enables and disables textures
		 * @param if the textures should be enabled or not
		 **/
		static void Enable(bool enableTextures);

		virtual std::string ResourceType();

    protected:

		unsigned int glId;	/**< Holds the opengl texture id        */
		unsigned int width;	/**< Stores the width of the texture    */
        unsigned int height;    /**< Stores the height of the texture   */

};

} /* lavish */

#endif	/* _TEXTURE_HPP */

