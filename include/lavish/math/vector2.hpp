/* 
 * File:   vector2.hpp
 * Author: Sean Chapel
 *
 * Created on May 30, 2009, 4:10 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _VECTOR2_HPP
#define	_VECTOR2_HPP

#include <math.h>
#include <lavish/platform.hpp>

namespace lavish
{

/**
 * A generic math class for a vector with x y
 */
class LAVISH_DECLSPEC Vector2
{
    public:

        float x; /**< vector's x component */
        float y; /**< vector's y component */


        /**
         * A default constructor makes (0, 0, 0)
         */
        Vector2()
        {
                x = 0.0f;
                y = 0.0f;
        }


        /**
         * Constructor that takes in a C array of 2 floats
         * @param v the array to make into a vector
         */
        Vector2(const float* const v)
        {
                x = v[0];
                y = v[1];
        }


        /**
         * Copy constructor
         * @param v the vector to copy
         */
        Vector2(const Vector2 &v)
        {
                x = v.x;
                y = v.y;
        }


        /**
         * Constructor that takes three floats
         * @param x the vector's x component
         * @param y the vector's y component
         */
        Vector2( const float x, const float y)
        {
                this->x = x;
                this->y = y;
        }


        /**
         * @return a vector with all components being zero
         */
        static Vector2 Zero()
        {
            return Vector2(0.0f, 0.0f);
        }


         /**
         * @return a vector with all components being one
         */
        static Vector2 One()
        {
            return Vector2(1.0f, 1.0f);
        }


        /**
         * @return a vector with the X axis having a one
         */
        static Vector2 UnitX()
        {
            return Vector2(1.0f, 0.0f);
        }


        /**
         * @return a vector with the Y axis having a one
         */
        static Vector2 UnitY()
        {
            return Vector2(0.0f, 1.0f);
        }


        /**
         * A default destructor
         */
        ~Vector2()
        {
        }


        /**
         * Negate operator
         */
        Vector2 operator - () const
        {
                return Vector2( -x, -y);
        }


        /**
         * Equals operator
         */
         const Vector2& operator = (const Vector2 &rhs)
        {
                x = rhs.x;
                y = rhs.y;
                return *this;
        }


        /**
         * Plus equals operator
         **/
        const Vector2& operator += (const Vector2 &rhs)
        {
                x += rhs.x;
                y += rhs.y;
                return *this;
        }


        /**
         * Minus equals operator
         */
        const Vector2& operator -= (const Vector2 &rhs)
        {
                x -= rhs.x;
                y -= rhs.y;
                return *this;
        }


        /**
         * Multiply equals operator
         */
        const Vector2& operator *= (const float &f)
        {
                x *= f;
                y *= f;
                return *this;
        }


        /**
         * Divide equal operator
         */
        const Vector2& operator /= (const float &f)
        {
                x /= f;
                y /= f;
                return *this;
        }


        /**
         * Plus operator
         */
        Vector2 operator + (const Vector2 &rhs) const
        {
                return Vector2( x + rhs.x , y + rhs.y);
        }


        /**
         * Minus operator
         */
        Vector2 operator - (const Vector2 &rhs) const
        {
                return Vector2( x - rhs.x , y - rhs.y);
        }


        /**
         * Normalize the vector
         */
        void Normalize()
        {
                float normal = sqrt((x * x) + (y * y));

                x /= normal;
                y /= normal;
        }

};


} /* lavish */



#endif	/* _VECTOR2_HPP */

