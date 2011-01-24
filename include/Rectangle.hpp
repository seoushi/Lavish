/* 
 * File:   rectangle.hpp
 * Author: Sean Chapel
 *
 * Created on May 29, 2009, 10:59 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _RECTANGLE_HPP
#define	_RECTANGLE_HPP

namespace lavish
{


/**
 * It's a rectangle
 */
class Rectangle
{
    public:

        /**
         * A default constructor
         */
        Rectangle();

        /**
         * A convenience constructor for a rectangle defining all values
         * @param x1 the first x coordinate
         * @param y1 the first y coordinate
         * @param x2 the second x coordinate
         * @param y2 the second y coordinate
         */
        Rectangle(float x1, float y1, float x2, float y2);

        /**
         * Gets the distance between x1 and x2
         * @return the width
         */
        float Width();

        /**
         * Gets the distance between y1 and y2
         * @return the height
         */
        float Height();


        float x1; /**< the first x coordinate   */
        float y1; /**< the first y coordinate   */
        float x2; /**< the second x coordinate  */
        float y2; /**< the second y coordinate  */
};


} /* lavish */

#endif	/* _RECTANGLE_HPP */

