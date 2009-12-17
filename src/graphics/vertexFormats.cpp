
/*
 * File:   vertexFormats.cpp
 * Author: Sean Chapel
 *
 * Created on May 30, 2009, 5:22 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */


#include <lavish/vertexFormats.hpp>
#include <lavish/platform.hpp>


namespace lavish
{


//
// VertexNormalTexture
//

VertexNormalTexture::VertexNormalTexture(Vector3 position, Vector3 normal, Vector2 textureCoords)
{
    this->position = position;
    this->normal = normal;
    this->textureCoords = textureCoords;
}


void VertexNormalTexture::SetupDraw()
{
    int size = sizeof(Vector3) + sizeof(Vector3) + sizeof(Vector2);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT,    size, (char*)NULL + 0);
    glNormalPointer(GL_FLOAT,       size, (char*)NULL + sizeof(Vector3));
    glTexCoordPointer(2, GL_FLOAT,  size, (char*)NULL + sizeof(Vector3) + sizeof(Vector3));
}


void VertexNormalTexture::TeardownDraw()
{
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}



//
// VertexTexture
//

VertexTexture::VertexTexture(Vector3 position, Vector2 textureCoords)
{
    this->position = position;
    this->textureCoords = textureCoords;
}

void VertexTexture::SetupDraw()
{
    int size = sizeof(Vector3) + sizeof(Vector2);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(3, GL_FLOAT,    size, (char*)NULL + 0);
    glTexCoordPointer(2, GL_FLOAT,  size, (char*)NULL + sizeof(Vector3));
}

void VertexTexture::TeardownDraw()
{
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}


//
// VertexNormalColor
//

VertexNormalColor::VertexNormalColor(Vector3 position, Vector3 normal, Color color)
{
    this->position = position;
    this->normal = normal;
    this->color = color;
}


void VertexNormalColor::SetupDraw()
{
    int size = sizeof(Vector3) + sizeof(Vector3) + sizeof(Color);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT,        size, (char*)NULL + 0);
    glNormalPointer(GL_FLOAT,           size, (char*)NULL + sizeof(Vector3));
    glColorPointer(4, GL_FLOAT, size, (char*)NULL + sizeof(Vector3));
}


void VertexNormalColor::TeardownDraw()
{
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}



//
// VertexColor
//

VertexColor::VertexColor(Vector3 position, Color color)
{
    this->position = position;
    this->color = color;
}


void VertexColor::SetupDraw()
{
    int size = sizeof(Vector3) + sizeof(Color);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT,        size, (char*)NULL + 0);
    glColorPointer(4, GL_FLOAT, size, (char*)NULL + sizeof(Vector3));
}


void VertexColor::TeardownDraw()
{
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}



} /* lavish */
