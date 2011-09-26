/* 
 * File:   font.cpp
 * Author: Sean Chapel
 *
 * Created on Sept 29, 2010, 8:50 PM
 * Copyright 2010 Seoushi Games. All rights reserved.
 */

#include <lavish/graphics/font.hpp>
#include <fstream>
#include <algorithm>
#include <memory>

namespace lavish
{


Glyph::Glyph()
{
	sprite = NULL;
	xOffset = yOffset = advance = 0;
}

Glyph::~Glyph()
{}


void Glyph::Render(std::shared_ptr<Matrix4> transformations)
{
	auto mat = std::make_shared<Matrix4>();
	
	// move to proper location for drawing
	if(transformations)
	{
		(*mat) = (*transformations);
	}
	
	(*mat) *= (*Matrix4::Translate((float)xOffset, (float)yOffset, 0));

	// draw the glyph
	sprite->Render(mat);
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
	
	texture = std::make_shared<Texture>();
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
			auto glyph = std::make_shared<Glyph>();
			
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

			glyph->sprite = std::shared_ptr<Sprite>(new Sprite(texture, (float)w, (float)h, (float)x, (float)y, true));
			
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
	texture = std::shared_ptr<Texture>(NULL);
	glyphs.clear();
}

        
void Font::DrawString(std::wstring text, std::shared_ptr<Matrix4> transformations)
{
	auto glyph = std::make_shared<Glyph>();
	auto mat = std::make_shared<Matrix4>();
	
	if(transformations)
	{
		(*mat) = (*transformations);
	}

	// render all glyphs
	std::for_each(begin(text), end(text), [&glyph, this, &mat](char c){
		glyph = this->glyphs[c];
		
		if(glyph.get() != NULL)
		{
			glyph->Render(mat);
			(*mat) *= (*Matrix4::Translate((float)glyph->advance, 0.0f, 0.0f));
		}
	});
}


int Font::StringWidth(std::wstring text)
{
	int width = 0;
	std::shared_ptr<Glyph> glyph;
	
	std::for_each(begin(text), end(text), [&glyph, this, &width](char c){
		glyph = glyphs[c];
		
		if(glyph)
		{
			width += glyph->advance;
		}
	});
	
	return width;
}
	
	
int Font::LineHeight()
{
	return lineHeight;
}

std::string Font::ResourceType() {
	return "font";
}

} /* lavish */
