/* 
 * File:   vector3.hpp
 * Author: Sean Chapel
 *
 * Created on May 30, 2009, 4:01 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _VECTOR3_HPP
#define	_VECTOR3_HPP

#include <math.h>
#include <lavish/core/platform.hpp>

namespace lavish
{

/**
 * A generic math class for a vector with x y and z
 */
class Vector3
{
    public:

        float x; /**< vector's x component */
        float y; /**< vector's y component */
        float z; /**< vector's z component */


        /**
         * A default constructor makes (0, 0, 0)
         */
        Vector3()
        {
                x = 0.0f;
                y = 0.0f;
                z = 0.0f;
        }


        /**
         * Constructor that takes in a C array of 3 floats
         * @param v the array to make into a vector
         */
        Vector3(const float* const v)
        {
                x = v[0];
                y = v[1];
                z = v[2];
        }


        /**
         * Copy constructor
         * @param v the vector to copy
         */
        Vector3(const Vector3 &v)
        {
                x = v.x;
                y = v.y;
                z = v.z;
        }


        /**
         * Constructor that takes three floats
         * @param x the vector's x component
         * @param y the vector's y component
         * @param z the vector's z component
         */
        Vector3( const float x, const float y, const float z)
        {
                this->x = x;
                this->y = y;
                this->z = z;
        }


        /**
         * @return a vector with all components being zero
         */
        static Vector3 Zero()
        {
            return Vector3(0.0f, 0.0f, 0.0f);
        }


         /**
         * @return a vector with all components being one
         */
        static Vector3 One()
        {
            return Vector3(1.0f, 1.0f, 1.0f);
        }


        /**
         * @return a vector with the X axis having a one
         */
        static Vector3 UnitX()
        {
            return Vector3(1.0f, 0.0f, 0.0f);
        }


        /**
         * @return a vector with the Y axis having a one
         */
        static Vector3 UnitY()
        {
            return Vector3(0.0f, 1.0f, 0.0f);
        }


        /**
         * @return a vector with the Z axis having a one
         */
        static Vector3 UnitZ()
        {
            return Vector3(0.0f, 0.0f, 1.0f);
        }


        /**
         * A default destructor
         */
        ~Vector3()
        {
        }


        /**
         * Negate operator
         */
        Vector3 operator - () const
        {
                return Vector3( -x, -y, -z );
        }


        /**
         * Equals operator
         */
         const Vector3& operator = (const Vector3 &rhs)
        {
                x = rhs.x;
                y = rhs.y;
                z = rhs.z;
                return *this;
        }


        /**
         * Plus equals operator
         **/
        const Vector3& operator += (const Vector3 &rhs)
        {
                x += rhs.x;
                y += rhs.y;
                z += rhs.z;
                return *this;
        }


        /**
         * Minus equals operator
         */
        const Vector3& operator -= (const Vector3 &rhs)
        {
                x -= rhs.x;
                y -= rhs.y;
                z -= rhs.z;
                return *this;
        }


        /**
         * Multiply equals operator
         */
        const Vector3& operator *= (const float &f)
        {
                x *= f;
                y *= f;
                z *= f;
                return *this;
        }


        /**
         * Divide equal operator
         */
        const Vector3& operator /= (const float &f)
        {
                x /= f;
                y /= f;
                z /= f;
                return *this;
        }


        /**
         * Plus operator
         */
        Vector3 operator + (const Vector3 &rhs) const
        {
                return Vector3( x + rhs.x , y + rhs.y, z + rhs.z );
        }


        /**
         * Minus operator
         */
        Vector3 operator - (const Vector3 &rhs) const
        {
                return Vector3( x - rhs.x , y - rhs.y, z - rhs.z );
        }

        /**
         * Dot product operator
         */
        const float operator * (const Vector3 &rhs) const
        {
                return  (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
        }

        /**
         * Cross product operator
         */
        Vector3 operator ^ ( const Vector3 &v ) const
        {
                return Vector3( ( y * v.z  -  z * v.y ),
                                ( z * v.x  -  x * v.z ),
                                ( x * v.y  -  y * v.x ) );
        }

        /**
         * Normalize the vector
         */
        void Normalize()
        {
                float normal = sqrt((x * x) + (y * y) + (z * z));

                x /= normal;
                y /= normal;
                z /= normal;
        }

        /**
         * Computes the normal of a plane defined by three vectors
         * @param v1 the first vector
         * @param v2 the first vector
         * @param v3 the first vector
         * @return the normal of the three input vectors
         */
        Vector3 ComputeNormal(const Vector3 &v1, const Vector3 &v2, const Vector3 &v3)
        {
                Vector3 out, vec1, vec2;

                vec1 = v1 - v2;
                vec2 = v1 - v3;

                out = vec1 ^ vec2;
                out.Normalize();

                return out;
        }

        /**
         * Compute the normal of a plane defined by two vectors
         * @param v1 the first vector
         * @param v2 the first vector
         * @return the normal of the two input vectors
         */
        Vector3 ComputeNormal(const Vector3 &v2, const Vector3 &v3)
        {
                Vector3 out, vec1, vec2;

                vec1 = *this - v2;
                vec2 = *this - v3;

                out = vec1 ^ vec2;
                out.Normalize();

                return out;
        }


};


} /* lavish */

#endif	/* _VECTOR3_HPP */

