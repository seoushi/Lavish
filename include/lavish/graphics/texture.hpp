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
         * A default constructor
         */
        Texture();

        
        /**
         * A constructor that takes a path to a file
         * This will throw an exception if the file cannot be loaded successfully
         */
        Texture(std::string filename);

        
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
         * Loads a texture from a file
         * @param the path to the file
         * @return if the texture was loaded successfully
         */
        bool Load(std::string filename);


        /**
         * Virtual function from the resource class
         */
        virtual void Dispose();


        /**
         * Reloads the texture from file
         * @return if the texture was loaded successfully
         */
        bool Reload();


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

    protected:

	unsigned int glId;	/**< Holds the opengl texture id        */
	unsigned int width;	/**< Stores the width of the texture    */
        unsigned int height;    /**< Stores the height of the texture   */

};

} /* lavish */

#endif	/* _TEXTURE_HPP */

