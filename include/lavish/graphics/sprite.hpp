/* 
 * File:   sprite.hpp
 * Author: Sean Chapel
 *
 * Created on May 29, 2009, 10:50 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _SPRITE_HPP
#define	_SPRITE_HPP

#include <lavish/renderable.hpp>
#include <lavish/resource.hpp>
#include <lavish/texture.hpp>
#include <lavish/common/rectangle.hpp>
#include <lavish/vertexBuffer.hpp>
#include <lavish/platform.hpp>

namespace lavish
{

class LAVISH_DECLSPEC Sprite : public Renderable, public Resource
{

    public:

        /**
         * A convenience constructor for a sprite that defines the texture and area to use
         * @param tex the texture to use
         * @param w the width of the sprite
         * @param h the height of the sprite
         * @param x the left most value on the texture for the sprite
         * @param y the bottom most value on the texture for the sprite
         * @param isInPixels true means the values are in pixel coordinates and not clamped between 0.0f and 1.0f
         */
        Sprite(Texture* tex, float w = 1.0f, float h = 1.0f, float x = 0.0f, float y = 0.0f, bool isInPixels = false);


        /**
         * A convenience constructor for a sprite that defines the texture and area to use with a Rectangle
         * @param tex the texture to use
         * @param rect the Rectangle of the area of the sprite
         * @param isInPixels true means the values are in pixel coordinates and not clamped between 0.0f and 1.0f
         */
        Sprite(Texture* tex, Rectangle &rect, bool isInPixels = false);


        /**
         * A default destructor
         */
        virtual ~Sprite();


        /**
         * Loads a sprite given the parameters
         * @param tex the texture to use
         * @param rect the Rectangle of the area of the sprite
         * @param isInPixels true means the values are in pixel coordinates and not clamped between 0.0f and 1.0f
         * @return if the sprite was loaded
         */
        bool Load(Texture* tex, Rectangle &rect, bool isInPixels = false);

         /**
         * Virtual function from the resource class
         */
        virtual void Dispose();

        
        /**
         * Implements the Renderable virtual function
         * Renders from the bottom left (0,0) upwards
         */
        virtual void Render(Matrix4* transformations = 0);

    private:

        Texture* texture;
        Rectangle area;
        VertexBuffer<VertexTexture> geometry;

};

} /* lavish */

#endif	/* _SPRITE_HPP */

