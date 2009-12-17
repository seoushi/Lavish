/*
 * File:   rectangle.cpp
 * Author: Sean Chapel
 *
 * Created on May 29, 2009, 10:59 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <lavish/rectangle.hpp>
#include <math.h>

namespace lavish
{

Rectangle::Rectangle()
{
    x1 = 0.0f;
    y1 = 0.0f;
    x2 = 0.0f;
    y2 = 0.0f;
}


Rectangle::Rectangle(float x1, float y1, float x2, float y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}


float Rectangle::Width()
{
    return fabs(x1 - x2);
}


float Rectangle::Height()
{
    return fabs(y1 - y2);
}


} /* lavish */



