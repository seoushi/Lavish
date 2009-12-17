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
#include <lavish/resource.hpp>
#include <lavish/platform.hpp>

namespace lavish
{

/**
 * A class that defines a texture
 */
class LAVISH_DECLSPEC Texture : public Resource
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

    protected:

	unsigned int glId;	/**< Holds the opengl texture id        */
	unsigned int width;	/**< Stores the width of the texture    */
        unsigned int height;    /**< Stores the height of the texture   */

};

} /* lavish */

#endif	/* _TEXTURE_HPP */

