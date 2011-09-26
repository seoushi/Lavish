/*
 * File:   Matrix4.cpp
 * Author: Sean Chapel
 *
 * Created on June 8, 2009, 9:00 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <memory>

#include <lavish/math/matrix4.hpp>
#include <lavish/math/math.hpp>
#include <lavish/core/platform.hpp>


namespace lavish
{


Matrix4::Matrix4()
{
	// make identity matrix
	memset(data, 0, 16 * sizeof(float) );
    m00 = m11 = m22 = m33 = 1.0f;
}


Matrix4::Matrix4(float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23,
                float m30, float m31, float m32, float m33)
{
    this->m00 = m00;
    this->m01 = m01;
    this->m02 = m02;
    this->m03 = m03;


    this->m10 = m10;
    this->m11 = m11;
    this->m12 = m12;
    this->m13 = m13;

    this->m20 = m20;
    this->m21 = m21;
    this->m22 = m22;
    this->m23 = m23;

    this->m30 = m30;
    this->m31 = m31;
    this->m32 = m32;
    this->m33 = m33;
}


Matrix4::Matrix4(const Matrix4 &m)
{
    *this = m;
}


Matrix4::~Matrix4()
{
}

	
std::shared_ptr<Matrix4> Matrix4::Identity()
{
	return std::make_shared<Matrix4>();
}

	
void Matrix4::Transpose()
{
    Matrix4 m( m00, m10, m20, m30,
              m01, m11, m21, m31,
              m02, m12, m22, m32,
              m03, m13, m23, m33 );

    memcpy(data, m.data, 16 * sizeof(float) );
}


std::shared_ptr<Matrix4> Matrix4::Transposed()
{
    return std::shared_ptr<Matrix4>( new Matrix4(m00, m10, m20, m30,
										m01, m11, m21, m31,
										m02, m12, m22, m32,
										m03, m13, m23, m33 ));
}


std::shared_ptr<Matrix4> Matrix4::RotateX( const float degrees )
{
	auto m = std::make_shared<Matrix4>();

    float  sr = (float)sin( (degrees * PI_OVER_180) );
    float  cr = (float)cos( (degrees * PI_OVER_180) );

    m->m11 =  cr;
    m->m21 = -sr;
    m->m12 =  sr;
    m->m22 =  cr;

    return m;
}


std::shared_ptr<Matrix4> Matrix4::RotateY( const float degrees )
{
    auto m = std::make_shared<Matrix4>();

    float  sr = (float)sin( (degrees * PI_OVER_180) );
    float  cr = (float)cos( (degrees * PI_OVER_180) );

    m->m00 =  cr;
    m->m20 =  sr;
    m->m02 = -sr;
    m->m22 =  cr;

    return m;
}


std::shared_ptr<Matrix4> Matrix4::RotateZ( const float degrees )
{
    auto m = std::make_shared<Matrix4>();

    float  sr = (float)sin( (degrees * PI_OVER_180) );
    float  cr = (float)cos( (degrees * PI_OVER_180) );

    m->m00 =  cr;
    m->m10 = -sr;
    m->m01 =  sr;
    m->m11 =  cr;

    return m;
}


std::shared_ptr<Matrix4> Matrix4::Scale( const float x, const float y, const float z )
{
    auto m = std::make_shared<Matrix4>();

    m->m00 = x;
    m->m11 = y;
    m->m22 = z;

    return m;
}


std::shared_ptr<Matrix4> Matrix4::Scale(const Vector3 &v)
{
    auto m = std::make_shared<Matrix4>();

    m->m00 = v.x;
    m->m11 = v.y;
    m->m22 = v.z;

    return m;
}


void Matrix4::GetScale(float* x, float* y, float* z)
{
    (*x) = m00;
    (*y) = m11;
    (*z) = m22;
}


void Matrix4::GetScale(Vector3* v) const
{
    v->x = m00;
    v->y = m11;
    v->z = m22;
}


std::shared_ptr<Matrix4> Matrix4::Translate( const float x, const float y, const float z)
{
	auto m = std::make_shared<Matrix4>();

    m->m30 = x;
    m->m31 = y;
    m->m32 = z;

    return m;
}


std::shared_ptr<Matrix4> Matrix4::Translate( const Vector3 &v )
{
    auto m = std::make_shared<Matrix4>();

    m->m30 = v.x;
    m->m31 = v.y;
    m->m32 = v.z;

    return m;
}


void Matrix4::GetTranslation(float* x,float* y, float* z) const
{
    (*x) = m03;
    (*y) = m13;
    (*z) = m23;
}


void Matrix4::GetTranslation(Vector3* v) const
{
    v->x = m13;
    v->y = m23;
    v->z = m33;
}

void Matrix4::SubMatrix3x3(int i,int j,float* mat) const
{
    int ti, tj, idst = 0, jdst = 0;

    for ( ti = 0; ti < 4; ti++ )
    {
        if ( ti < i )
        {
            idst = ti;
        }
        else if ( ti > i )
        {
            idst = ti-1;
        }

        for ( tj = 0; tj < 4; tj++ )
        {
            if ( tj < j )
            {
                jdst = tj;
            }
            else if ( tj > j )
            {
                jdst = tj-1;
            }

            if ( ti != i && tj != j )
            {
                mat[idst*3 + jdst] = data[ti*4 + tj];
            }
        }
    }
}


void Matrix4::FastInverse(Matrix4* result)
{
    float *ptr = data;

    result->data[0]   = *(  ptr);
    result->data[4]   = *(++ptr);
    result->data[8]   = *(++ptr);

    float Tx		 = *(++ptr);

    result->data[1]   = *(++ptr);
    result->data[5]   = *(++ptr);
    result->data[9]   = *(++ptr);

    float Ty		 = *(++ptr);

    result->data[2]   = *(++ptr);
    result->data[6]   = *(++ptr);
    result->data[10]  = *(++ptr);

    float Tz	     = *(++ptr);

    ptr = data;

    result->m03  = - *(  ptr) * Tx;
    result->m13  = - *(++ptr) * Tx;
    result->m23  = - *(++ptr) * Tx;
    ++ptr;
    result->m03  -=  *(++ptr) * Ty;
    result->m13  -=  *(++ptr) * Ty;
    result->m23  -=  *(++ptr) * Ty;
    ++ptr;
    result->m03  -=  *(++ptr) * Tz;
    result->m13  -=  *(++ptr) * Tz;
    result->m23  -=  *(++ptr) * Tz;
}


bool Matrix4::Inverse(Matrix4* result) const
{
    float determinant = Determinant();
    float matrixSub3x3[9];

    int i, j, sign;


    if ( fabs(determinant) < 0.0005 )
    {
        return false;
    }

    for ( i = 0; i < 4; i++ )
    {
        for ( j = 0; j < 4; j++ )
        {
            sign = 1 - ( (i +j) % 2 ) * 2;

            SubMatrix3x3( i, j, matrixSub3x3 );

            float det =   matrixSub3x3[0] * ( matrixSub3x3[4]*matrixSub3x3[8] - matrixSub3x3[7]*matrixSub3x3[5] )
                            - matrixSub3x3[1] * ( matrixSub3x3[3]*matrixSub3x3[8] - matrixSub3x3[6]*matrixSub3x3[5] )
                            + matrixSub3x3[2] * ( matrixSub3x3[3]*matrixSub3x3[7] - matrixSub3x3[6]*matrixSub3x3[4] );

            result->data[i+j*4] = ( det * sign ) / determinant;
        }
    }

    return true;
}


bool Matrix4::Inverse()
{
    Matrix4 inv;
    bool result = Inverse(&inv);

    *this = inv;
    return result;
}


float Matrix4::Determinant() const
{
    float det, result = 0, i = 1;
    float matrixSub3x3[9];

    for( int n = 0; n < 4; n++, i *= -1 )
    {
        SubMatrix3x3( 0, n, matrixSub3x3 );

        det =     matrixSub3x3[0] * ( matrixSub3x3[4]*matrixSub3x3[8] - matrixSub3x3[7]*matrixSub3x3[5] )
                - matrixSub3x3[1] * ( matrixSub3x3[3]*matrixSub3x3[8] - matrixSub3x3[6]*matrixSub3x3[5] )
                + matrixSub3x3[2] * ( matrixSub3x3[3]*matrixSub3x3[7] - matrixSub3x3[6]*matrixSub3x3[4] );

        result += data[n] * det * i;
    }

    return result;
}


const bool Matrix4::operator==(const Matrix4 &m) const
{
    // guess all Matrix4 elements are the same
    return  (m00 == m.m00) &&
            (m01 == m.m01) &&
            (m02 == m.m02) &&
            (m03 == m.m03) &&

            (m10 == m.m10) &&
            (m11 == m.m11) &&
            (m12 == m.m12) &&
            (m13 == m.m13) &&

            (m20 == m.m20) &&
            (m21 == m.m21) &&
            (m22 == m.m22) &&
            (m23 == m.m23) &&

            (m30 == m.m30) &&
            (m31 == m.m31) &&
            (m32 == m.m32) &&
            (m33 == m.m33);
}

const bool Matrix4::operator!=( const Matrix4 &m)
{
    return !(m == *this);
}


const Matrix4& Matrix4::operator=(const Matrix4 &rhs)
{
    m00  = rhs.m00;
    m01  = rhs.m01;
    m02  = rhs.m02;
    m03  = rhs.m03;

    m10  = rhs.m10;
    m11  = rhs.m11;
    m12  = rhs.m12;
    m13  = rhs.m13;

    m20  = rhs.m20;
    m21  = rhs.m21;
    m22  = rhs.m22;
    m23  = rhs.m23;

    m30  = rhs.m30;
    m31  = rhs.m31;
    m32  = rhs.m32;
    m33  = rhs.m33;

    return *this;
}


const Matrix4& Matrix4::operator*=( const float &f)
{
    for(int i = 0; i < 16; i++)
    {
        data[i] *= f;
    }

    return *this;
}


const Matrix4& Matrix4::operator /= ( const float &f)
{
    for(int i = 0; i < 16; i++)
    {
        data[i] /= f;
    }

    return *this;
}


const Matrix4& Matrix4::operator *= (const Matrix4 &m)
{
    Matrix4 temp(*this);

    //	row 0
    m00  =  temp.m00 * m.m00;
    m01  =  temp.m01 * m.m00;
    m02  =  temp.m02 * m.m00;
    m03  =  temp.m03 * m.m00;

    m00 +=  temp.m10 * m.m01;
    m01 +=  temp.m11 * m.m01;
    m02 +=  temp.m12 * m.m01;
    m03 +=  temp.m13 * m.m01;

    m00 +=  temp.m20 * m.m02;
    m01 +=  temp.m21 * m.m02;
    m02 +=  temp.m22 * m.m02;
    m03 +=  temp.m23 * m.m02;

    m00 +=  temp.m30 * m.m03;
    m01 +=  temp.m31 * m.m03;
    m02 +=  temp.m32 * m.m03;
    m03 +=  temp.m33 * m.m03;


    //	row 1
    m10  =  temp.m00 * m.m10;
    m11  =  temp.m01 * m.m10;
    m12  =  temp.m02 * m.m10;
    m13  =  temp.m03 * m.m10;

    m10 +=  temp.m10 * m.m11;
    m11 +=  temp.m11 * m.m11;
    m12 +=  temp.m12 * m.m11;
    m13 +=  temp.m13 * m.m11;

    m10 +=  temp.m20 * m.m12;
    m11 +=  temp.m21 * m.m12;
    m12 +=  temp.m22 * m.m12;
    m13 +=  temp.m23 * m.m12;

    m10 +=  temp.m30 * m.m13;
    m11 +=  temp.m31 * m.m13;
    m12 +=  temp.m32 * m.m13;
    m13 +=  temp.m33 * m.m13;


    //	row 2
    m20  =  temp.m00 * m.m20;
    m21  =  temp.m01 * m.m20;
    m22  =  temp.m02 * m.m20;
    m23  =  temp.m03 * m.m20;

    m20 +=  temp.m10 * m.m21;
    m21 +=  temp.m11 * m.m21;
    m22 +=  temp.m12 * m.m21;
    m23 +=  temp.m13 * m.m21;

    m20 +=  temp.m20 * m.m22;
    m21 +=  temp.m21 * m.m22;
    m22 +=  temp.m22 * m.m22;
    m23 +=  temp.m23 * m.m22;

    m20 +=  temp.m30 * m.m23;
    m21 +=  temp.m31 * m.m23;
    m22 +=  temp.m32 * m.m23;
    m23 +=  temp.m33 * m.m23;


    //	row 3
    m30  =  temp.m00 * m.m30;
    m31  =  temp.m01 * m.m30;
    m32  =  temp.m02 * m.m30;
    m33  =  temp.m03 * m.m30;

    m30 +=  temp.m10 * m.m31;
    m31 +=  temp.m11 * m.m31;
    m32 +=  temp.m12 * m.m31;
    m33 +=  temp.m13 * m.m31;

    m30 +=  temp.m20 * m.m32;
    m31 +=  temp.m21 * m.m32;
    m32 +=  temp.m22 * m.m32;
    m33 +=  temp.m23 * m.m32;

    m30 +=  temp.m30 * m.m33;
    m31 +=  temp.m31 * m.m33;
    m32 +=  temp.m32 * m.m33;
    m33 +=  temp.m33 * m.m33;
    return *this;
}


Matrix4  Matrix4::operator * (const Matrix4 &m) const
{
    Matrix4 temp = *this;

    // row 0
    temp.m00  =  m00 * m.m00;
    temp.m01  =  m01 * m.m00;
    temp.m02  =  m02 * m.m00;
    temp.m03  =  m03 * m.m00;

    temp.m00 +=  m10 * m.m01;
    temp.m01 +=  m11 * m.m01;
    temp.m02 +=  m12 * m.m01;
    temp.m03 +=  m13 * m.m01;

    temp.m00 +=  m20 * m.m02;
    temp.m01 +=  m21 * m.m02;
    temp.m02 +=  m22 * m.m02;
    temp.m03 +=  m23 * m.m02;

    temp.m00 +=  m30 * m.m03;
    temp.m01 +=  m31 * m.m03;
    temp.m02 +=  m32 * m.m03;
    temp.m03 +=  m33 * m.m03;


    //	row 1
    temp.m10  =  m00 * m.m10;
    temp.m11  =  m01 * m.m10;
    temp.m12  =  m02 * m.m10;
    temp.m13  =  m03 * m.m10;

    temp.m10 +=  m10 * m.m11;
    temp.m11 +=  m11 * m.m11;
    temp.m12 +=  m12 * m.m11;
    temp.m13 +=  m13 * m.m11;

    temp.m10 +=  m20 * m.m12;
    temp.m11 +=  m21 * m.m12;
    temp.m12 +=  m22 * m.m12;
    temp.m13 +=  m23 * m.m12;

    temp.m10 +=  m30 * m.m13;
    temp.m11 +=  m31 * m.m13;
    temp.m12 +=  m32 * m.m13;
    temp.m13 +=  m33 * m.m13;


    //	row 2
    temp.m20  =  m00 * m.m20;
    temp.m21  =  m01 * m.m20;
    temp.m22  =  m02 * m.m20;
    temp.m23  =  m03 * m.m20;

    temp.m20 +=  m10 * m.m21;
    temp.m21 +=  m11 * m.m21;
    temp.m22 +=  m12 * m.m21;
    temp.m23 +=  m13 * m.m21;

    temp.m20 +=  m20 * m.m22;
    temp.m21 +=  m21 * m.m22;
    temp.m22 +=  m22 * m.m22;
    temp.m23 +=  m23 * m.m22;

    temp.m20 +=  m30 * m.m23;
    temp.m21 +=  m31 * m.m23;
    temp.m22 +=  m32 * m.m23;
    temp.m23 +=  m33 * m.m23;


    //	row 3
    temp.m30  =  m00 * m.m30;
    temp.m31  =  m01 * m.m30;
    temp.m32  =  m02 * m.m30;
    temp.m33  =  m03 * m.m30;

    temp.m30 +=  m10 * m.m31;
    temp.m31 +=  m11 * m.m31;
    temp.m32 +=  m12 * m.m31;
    temp.m33 +=  m13 * m.m31;

    temp.m30 +=  m20 * m.m32;
    temp.m31 +=  m21 * m.m32;
    temp.m32 +=  m22 * m.m32;
    temp.m33 +=  m23 * m.m32;

    temp.m30 +=  m30 * m.m33;
    temp.m31 +=  m31 * m.m33;
    temp.m32 +=  m32 * m.m33;
    temp.m33 +=  m33 * m.m33;
    return temp;
}


void Matrix4::Apply()
{
    glLoadMatrixf(data);
}


} /* lavish */

