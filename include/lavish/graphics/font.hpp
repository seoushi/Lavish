/* 
 * File:   font.hpp
 * Author: Sean Chapel
 *
 * Created on Sept 29, 2010, 8:50 PM
 * Copyright 2010 Seoushi Games. All rights reserved.
 */

#ifndef _FONT_HPP
#define	_FONT_HPP

#include <map>

#include <lavish/graphics/renderable.hpp>
#include <lavish/graphics/sprite.hpp>
#include <lavish/core/resource.hpp>
#include <lavish/graphics/texture.hpp>
#include <lavish/common/rectangle.hpp>
#include <lavish/graphics/vertexBuffer.hpp>
#include <lavish/core/platform.hpp>

namespace lavish
{
	
	/*
	 * Used internally by the Font class
	 */
	class Glyph : public Renderable
	{
		public:
			
			/**
			 * Default constructor for a glyph
			 */
			Glyph();
			
			/**
			 * Default destructor
			 */
			~Glyph();
			
			
			/**
			 * Implements the Renderable virtual function
			 * Renders from the bottom left (0,0) upwards
			 */
			virtual void Render(Matrix4* transformations = 0);
			
			
			Sprite* sprite;	/*< sprite of the glyph		*/
			int xOffset;	/*< x offset when drawing	*/
			int yOffset;	/*< y offset when drawing	*/
			int advance;	/*< the ammount to advance in the x direction after drawing	*/
	};
	
	
	class Font : public Resource
	{
		
    public:
		
        /**
         * Default constructor for a font
         */
		Font();
		
		
        /**
         * Default destructor
         */
        virtual ~Font();
		
		
        /**
         * Loads a font given the file name
		 * @param the name of the font file to load
		 * @param the name of the texture to use
         */
		bool Load(std::string filename, std::string textureName);
		
		/**
         * Virtual function from the resource class
         */
        virtual void Dispose();
		
        
        /**
         * Renders a string at a given location
		 * note: does not automatically switch to an ortho view 
		 * @param the string to draw
         * @param the transformation on where to start rendering
         */
        void DrawString(std::wstring text, Matrix4* transformations = 0);
		
		/**
		 * @param the string to get the width of
		 * @return the width of the given string
		 */
		int StringWidth(std::wstring text);
		

		/**
		 * @return the height of line of text
		 */
		int LineHeight();
		
    private:
		
		int	lineHeight;
        Texture* texture;
		std::map<int, Glyph*> glyphs;
        Rectangle area;
        VertexBuffer<VertexTexture> geometry;
		
	};
	
	
} /* lavish */

#endif	/* _FONT_HPP */
