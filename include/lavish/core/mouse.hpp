/* 
 * File:   mouse.hpp
 * Author: Sean Chapel
 *
 * Created on May 29, 2009, 1:35 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _MOUSE_HPP
#define	_MOUSE_HPP

#include <lavish/platform.hpp>

namespace lavish
{


namespace mouse
{


/**
* An enum of the mouse buttons
*/
enum LAVISH_DECLSPEC Button
{
    Left    = 1,
    Middle  = 2,
    Right   = 3
};


} /* mouse */



/**
 * A class that receives events related to the mouse.
 * it must be attached to an eventListener in order for it to receive events.
 */
class LAVISH_DECLSPEC MouseListener
{
    public:

        /**
         * A default constructor
         */
        MouseListener();


        /**
         * A virtual destructor
         */
        virtual ~MouseListener();


        /**
         * A pure virtual method that gets called when a mouse button is pressed
         * @param button a mouse button
         */
        virtual void OnButtonDown(const mouse::Button button) = 0;


        /**
         * A pure virtual method that gets called when a mouse button is released
         * @param button a mouse button
         */
        virtual void OnButtonUp(const mouse::Button button) = 0;


        /**
         * A pure virtual method that gets called when the mouse is moved
         * @param x the current x coordinate on the screen
         * @param y the current y coordinate on the screen
         * @param dx the movement in the x direction since the last event
         * @param dy the movement in the y direction since the last event
         */
        virtual void OnMouseMove(const unsigned int x, const unsigned int y, const int dx, const int dy) = 0;
};


} /* namespace lavish */

#endif	/* _MOUSE_HPP */
