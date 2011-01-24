/* 
 * File:   vertexFormats.hpp
 * Author: Sean Chapel
 *
 * Created on May 30, 2009, 5:22 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _VERTEXFORMATS_HPP
#define	_VERTEXFORMATS_HPP

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Platform.hpp"

namespace lavish
{

/**
 * A vertex with a position, normal and texture coords
 */
struct VertexNormalTexture
{

    /**
     * A constructor that initializes all components
     * @param position the verts position
     * @param normal the verts normal
     * @param textureCoords the verts texture coordinatess
     */
    VertexNormalTexture(Vector3 position, Vector3 normal, Vector2 textureCoords);


    /**
     * Used for setuping up drawing with this format used by VertexBuffers
     */
    static void SetupDraw();


    /**
     * Used for tearing down drawing with this format used by VertexBuffers
     */
    static void TeardownDraw();

    
    Vector3 position;       /**< position component             */
    Vector3 normal;         /**< normal component               */
    Vector2 textureCoords;  /**< texture coordinates component  */
};




/**
 * A vertex with a position and texture coords
 */
struct VertexTexture
{
    /**
     * A constructor that initializes all components
     * @param position the verts position
     * @param textureCoords the verts texture coordinatess
     */
    VertexTexture(Vector3 position, Vector2 textureCoords);


    /**
     * Used for setuping up drawing with this format used by VertexBuffers
     */
    static void SetupDraw();


    /**
     * Used for tearing down drawing with this format used by VertexBuffers
     */
    static void TeardownDraw();

    
    Vector3 position;       /**< position component             */
    Vector2 textureCoords;  /**< texture coordinates component  */
};


/**
 * A vertex with a position, normal and color
 */
struct VertexNormalColor
{

    /**
     * A constructor that initializes all components
     * @param position the verts position
     * @param normal the verts normal
     * @param color the verts color
     */
//    VertexNormalColor(Vector3 position, Vector3 normal, Color color);


    /**
     * Used for setuping up drawing with this format used by VertexBuffers
     */
    static void SetupDraw();


    /**
     * Used for tearing down drawing with this format used by VertexBuffers
     */
    static void TeardownDraw();
    

    Vector3 position;   /**< position component */
    Vector3 normal;     /**< normal component   */
//    Color color;        /**< color component    */
};


/**
 * A vertex with a position and color
 */
struct VertexColor
{

    /**
     * A constructor that initializes all components
     * @param position the verts position
     * @param normal the verts normal
     * @param color the verts color
     */
//    VertexColor(Vector3 position, Color color);


    /**
     * Used for setuping up drawing with this format used by VertexBuffers
     */
    static void SetupDraw();


    /**
     * Used for tearing down drawing with this format used by VertexBuffers
     */
    static void TeardownDraw();
    


    Vector3 position;   /**< position component */
//    Color color;        /**< color component    */
};



} /* lavish */



#endif	/* _VERTEXFORMATS_HPP */

