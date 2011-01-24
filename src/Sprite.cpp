/* 
 * File:   sprite.cpp
 * Author: Sean Chapel
 * 
 * Created on May 29, 2009, 10:50 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include "Sprite.hpp"
#include "Platform.hpp"

namespace lavish
{


Sprite::Sprite(Texture* tex, float w, float h, float x, float y, bool isInPixels)
{
    resourceType = resource::Sprite;
    Rectangle rect(x, y, x + w, y +h);

    Load(tex, rect, isInPixels);
}


Sprite::Sprite(Texture* tex, Rectangle &rect, bool isInPixels)
{
    resourceType = resource::Sprite;

    Load(tex, rect, isInPixels);
}


Sprite::~Sprite()
{
    Dispose();
}


bool Sprite::Load(Texture* tex, Rectangle &rect, bool isInPixels)
{
    if(!tex || !tex->IsLoaded())
    {
        return false;
    }

    Dispose();

    texture = tex;
    area = rect;

    geometry.SetSize(4);


    if(isInPixels)
    {
        //top left
        geometry.AddElement( VertexTexture( Vector3(0.0f, 0.0f, 0.0f),
                                            Vector2(rect.x1 / tex->Width(), rect.y2 / tex->Height())));
        //top right
        geometry.AddElement( VertexTexture( Vector3(rect.Width(), 0.0f, 0.0f),
                                            Vector2(rect.x2 / tex->Width(), rect.y2 / tex->Height())));
        //bottom left
        geometry.AddElement( VertexTexture( Vector3(0.0f, rect.Height(), 0.0f),
                                            Vector2(rect.x1 / tex->Width(), rect.y1 / tex->Height())));
        //bottom right
        geometry.AddElement( VertexTexture( Vector3(rect.Width(), rect.Height(), 0.0f),
                                            Vector2(rect.x2 / tex->Width(), rect.y1 / tex->Height())));
    }
    else
    {
        //top left
        geometry.AddElement( VertexTexture( Vector3(0.0f, 0.0f, 0.0f),
                                            Vector2(rect.x1, rect.y2)));
        //top right
        geometry.AddElement( VertexTexture( Vector3(rect.Width() * tex->Width(), 0.0f, 0.0f),
                                            Vector2(rect.x2, rect.y2)));
        //bottom left
        geometry.AddElement( VertexTexture( Vector3(0.0f, rect.Height() * tex->Height(), 0.0f),
                                            Vector2(rect.x1, rect.y1)));
        //bottom right
        geometry.AddElement( VertexTexture( Vector3(rect.Width() * tex->Width(), rect.Height() * tex->Height(), 0.0f),
                                            Vector2(rect.x2, rect.y1)));
    }

    geometry.Generate();

    isResourceLoaded = true;

    return true;
}

void Sprite::Dispose()
{
    if(isResourceLoaded)
    {
        geometry.Dispose();

        isResourceLoaded = false;
    }
}

void Sprite::Render(Matrix4* transformations)
{
    if(transformations)
    {
        transformations->Apply();
    }

    texture->Bind();
    geometry.Bind();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    geometry.Unbind();
}


} /* lavish */
