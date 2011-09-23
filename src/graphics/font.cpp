/* 
 * File:   font.cpp
 * Author: Sean Chapel
 *
 * Created on Sept 29, 2010, 8:50 PM
 * Copyright 2010 Seoushi Games. All rights reserved.
 */

#include <lavish/graphics/font.hpp>
#include <fstream>

namespace lavish
{


Glyph::Glyph()
{
	sprite = NULL;
	xOffset = yOffset = advance = 0;
}

Glyph::~Glyph()
{
	if(sprite)
	{
		delete sprite;
	}
}


void Glyph::Render(Matrix4* transformations)
{
	Matrix4 mat;
	
	// move to proper location for drawing
	if(transformations)
	{
		mat = (*transformations);
	}
	
	mat *= Matrix4::Translate((float)xOffset, (float)yOffset, 0);

	// draw the glyph
	sprite->Render(&mat);
}

	
	
	
Font::Font()
{
	texture = NULL;
}

	
Font::~Font()
{
	Dispose();
}


bool Font::Load(std::string filename, std::string textureName)
{
	std::ifstream file;
	file.open(filename.c_str(), std::ios::in);
	
	if(!file.is_open())
	{
		return false;
	}
	
	texture = new Texture();
	if(!texture->Load(textureName))
	{
		return false;
	}
	
	
	std::string element = "";
	int curChar;
	int x, y, w, h;

	//Parse file into elements
	while(!file.eof())
	{
		file >> element;

		if (element == "char")
		{
			Glyph* glyph = new Glyph();
			
			file >> element;
			curChar = atoi(element.c_str());
			
			file >> element;
			x = atoi(element.c_str());
			
			file >> element;
			y = atoi(element.c_str());
			
			file >> element;
			w = atoi(element.c_str());
			
			file >> element;
			h = atoi(element.c_str());

			glyph->sprite = new Sprite(texture, (float)w, (float)h, (float)x, (float)y, true);
			
			file >> element;
			glyph->xOffset = atoi(element.c_str());
			
			file >> element;
			glyph->yOffset = lineHeight - (h + atoi(element.c_str())); // since we draw upside down (bottom is 0 instead of top) we have to flip the y offset.
			
			file >> element;
			glyph->advance = atoi(element.c_str());
			
			glyphs[curChar] = glyph;
		}
		// ignore comments
		else if(element == "#")
		{
			getline(file, element);
		}
		else if(element == "lineHeight")
		{
			file >> element;
			lineHeight = atoi(element.c_str());
		}
	}
	
	file.close();
	
	return true;
}


void Font::Dispose()
{
	if(texture)
	{
		delete texture;
	}
	
	for (std::map<int, Glyph*>::iterator itr = glyphs.begin(); itr != glyphs.end(); itr++)
	{
		delete itr->second;
	}
	
	glyphs.clear();
}

        
void Font::DrawString(std::wstring text, Matrix4* transformations)
{
	Glyph* glyph;
	Matrix4 mat = Matrix4::Identity();
	
	if(transformations)
	{
		mat = (*transformations);
	}

	// render all glyphs
	for (std::wstring::iterator itr = text.begin(); itr != text.end(); itr++)
	{
		glyph = glyphs[(*itr)];
		
		if(glyph)
		{
			glyph->Render(&mat);
			mat *= Matrix4::Translate((float)glyph->advance, 0.0f, 0.0f);
		}
	}
}


int Font::StringWidth(std::wstring text)
{
	int width = 0;
	Glyph* glyph;
	
	for (std::wstring::iterator itr = text.begin(); itr != text.end(); itr++)
	{
		glyph = glyphs[(*itr)];
		
		if(glyph)
		{
			width += glyph->advance;
		}
	}
	
	return width;
}
	
	
int Font::LineHeight()
{
	return lineHeight;
}

} /* lavish */
