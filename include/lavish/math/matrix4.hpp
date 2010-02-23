/*
 * File:   Matrix4.hpp
 * Author: Sean Chapel
 *
 * Created on June 8, 2009, 9:00 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */


#ifndef _Matrix4_HPP
#define _Matrix4_HPP

#include <lavish/math/vector3.hpp>
#include <lavish/core/platform.hpp>

namespace lavish
{

/**
 * A 4x4 matrix class
 */
class LAVISH_DECLSPEC Matrix4
{
    public:

        union
        {
            float data[16];
	
            struct
            {
                float m00; float m01; float m02; float m03;
                float m10; float m11; float m12; float m13;
                float m20; float m21; float m22; float m23;
                float m30; float m31; float m32; float m33;
            };
        };


        /**
         * Default constructor
         * Makes an idenity matrix
         */
        Matrix4();

        /**
         * constructor that take all values of the matrix
         */
        Matrix4(float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23,
                float m30, float m31, float m32, float m33);

        /**
         * Constructor that takes another matrix
         * @param m the matrix to clone
         */
        Matrix4(const Matrix4 &m);

        /**
         * Default destructor
         */
        ~Matrix4();

        /**
         * Turns the matrix into an idenity matrix
         */
        void Identity();


        /**
         * Transposes the matrix
         */
        void Transpose();


        /**
         * @return the transposed version of the matrix
         */
        Matrix4 Transposed() const;


        /**
         * Makes a new Matrix rotated around the X axis
         * @param degrees the degrees to rotate
         * @return a matrix rotated around the X axis
         */
        Matrix4 static RotateX( const float degrees );


        /**
         * Makes a new Matrix rotated around the Y axis
         * @param degrees the degrees to rotate
         * @return a matrix rotated around the Y axis
         */
        Matrix4 static RotateY( const float degrees );


        /**
         * Makes a new Matrix rotated around the Z axis
         * @param degrees the degrees to rotate
         * @return a matrix rotated around the Z axis
         */
        Matrix4 static RotateZ( const float degrees );


        /**
         * Makes a new scaled Matrix
         * @param x the amount to scale on the X axis
         * @param y the amount to scale on the Y axis
         * @param z the amount to scale on the Z axis
         * @return a scaled matrix
         */
        Matrix4 static Scale( const float x, const float y , const float z );


        /**
         * Makes a new scaled Matrix
         * @param v a vector with the scale amounts
         * @return a scaled matrix
         */
        Matrix4 static Scale( const Vector3 &v);


        /**
         * Get's the scales for all axis
         * @param x the X axis scale reference
         * @param y the Y axis scale reference
         * @param z the Z axis scale reference
         */
        void GetScale(float* x, float* y, float* z);


        /**
         * Get's the scales for all axis
         * @param v a vector scales to populate
         */
        void GetScale(Vector3* v) const;


        /**
         * Makes a translation matrix
         * @param x the X axis translation
         * @param y the Y axis translation
         * @param z the Z axis translation
         * @return a translation matrix
         */
        Matrix4 static Translate( const float x, const float y, const float z);


        /**
         * Makes a translation matrix
         * @param v the vector to translate with
         * @return a translation matrix
         */
        Matrix4 static Translate( const Vector3 &v );


        /**
         * Get's the translations for all axis
         * @param x the X axis translation reference
         * @param y the Y axis translation reference
         * @param z the Z axis translation reference
         */
        void GetTranslation(float* x,float* y, float* z) const;


        /**
         * Get's the translations for all axis
         * @param v a vector translations to populate
         */
        void GetTranslation(Vector3* v) const;

        /**
         * Helper function to get part of matrix
         * @param i x-column to ignore
         * @param j y-column to ignore
         * @param mat the output matrix
         */
		void SubMatrix3x3(int i, int j, float* mat) const;


        /**
         * A fast method for inversing a matrix, it only works on affine matrices (translations and rotations only)
         * @param result the result of the inverse
         */
        void FastInverse(Matrix4* result);

        /**
         * A slower method for inversing a matrix, works on all matrices
         * @param result the result of the inverse
         * @return if the matrix could be inversed
         */
        bool Inverse(Matrix4* result) const;

        /**
         * Inverses the matrix
         * @return if the matrix could be inversed
         */
        bool Inverse();

        /**
         * @return the determinant of the matrix
         */
        float Determinant() const;


        /**
         * Compares two matrices for equality
         * @param the matrix to compare to
         * @return if the matrices are equal
         */
        const bool operator==(const Matrix4 &m) const;


        /**
         * Compares two matrices for inequality
         * @param the matrix to compare to
         * @return if the matrices are not equal
         */
        const bool operator!=( const Matrix4 &m);


        /**
         * assignment operator
         * @param rhs matrix values to assign with
         * @return a new matrix with the value of rhs
         */
        const Matrix4& operator=(const Matrix4 &rhs);


        /**
         * multiplication equals operator against a float, multiples it by all elements in a matrix
         * @param f float value to multiply with
         * @return a new multiplied matrix
         */
        const Matrix4& operator*=( const float &f);
        

        /**
         * divide equals operator against a float, divides it by all elements in a matrix
         * @param f float value to divide with
         * @return a new divided matrix
         */
        const Matrix4& operator /= ( const float &f);


        /**
         * multiplication equals operator against a matrix, applies a matrix transformations
         * @param m matrix to multiply with
         * @return a new transformed matrix
         */
        const Matrix4& operator *= ( const Matrix4 &m);

        /**
         * multiplication operator against a matrix, applies a matrix transformations
         * @param m matrix to multiply with
         * @return a new transformed matrix
         */
        Matrix4  operator * ( const Matrix4 &m) const;

        /**
         * Sets the matrix as the current opengl matrix
         */
        void Apply();
    };


} /* lavish */

#endif /* _Matrix4_HPP */
