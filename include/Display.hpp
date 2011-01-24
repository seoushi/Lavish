/* 
 * File:   Display.hpp
 *
 * Copyright © 2011, Sean Chapel
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef DISPLAY_HPP
#define	DISPLAY_HPP

#include <string>
#include <list>

#include "Platform.hpp"
#include "EventListener.hpp"
#include "Vector2.hpp"

namespace lavish
{


/**
 * The Display class handles the graphics window
 */
class Display
{
    public:
        
        /*
         * A default constructor
         */
        Display();

        /**
         * A default Destructor
         */
        ~Display();

        /**
         * Initializes the graphics library for window for creation.
         * This method must be called before Show().
         * This method does not create the window.
         *
         */
        bool init(int Width = 640, int Height = 480, int Bpp = 32, std::string WindowTitle = "", bool resizable = false);
	
        /**
         * @return a list of known valid display modes
         * Requires that Display has been initialized
         */
        std::list<Vector2> displayModes();

        /**
         * Clears the display
         */
        void clearScreen();

        /**
         * Flips backbuffer to the display
         */
        void swapBuffers();

        /**
         * Creates a window and shows it
         * Show() must be called before any graphics related functions are called
         * Initialize must be called before Show()
         * @return if the window was created correctly
         */
        bool show();

        /**
         * Resizes the window
         * All data on the graphics card such as textures and models are not guarenteed to still be valid after the operation
         * @return if the window was resized correctly
         */
        bool resize(int width, int height);

        /**
         * Toggles the display between windowed mode and fullscreen
         */
        void toggleFullScreen();

        /**
         * Get the current width of the display
         * @return the width of the display
         */
        int width();

        /**
         * Get the current height of the display
         * @return the height of the display
         */
        int height();

        /**
         * A helper function to setup the display's perspective
         * @param angle the angle for the foc of the camera
         * @param near the near plane to render from
         * @param far the far plane to render to
         */
        void setupPerspective(float angle, float near, float far);

        /**
         * A helper function to setup the display in 2d mode
         * Maps the screen by pixels
         * left is 0
         * right is the window's width
         * top is the window's height
         * bottom is 0
         * near and far are between 0 and 100
         */
        void setup2d();

        /**
         * The event listener for the display
         * @return EventListener
         */
        EventListener* listener();
	
        /**
         * Sets if the mouse cursor is shown
         **/
        void showMouseCursor(bool isShown);

        /**
         * Sets if the windows should grab the input.
         * by default this is off. This only affects windowed mode as fullscreen always grabs the input
         **/
        void grabInput(bool shouldGrabInput);

        
    protected:

        int _width;               /**< Stores the width of the drawing area     */
        int _height;              /**< Stores the height of the drawing area    */
        int _bpp;                 /**< Stores the bits per pixel of the screen  */
        std::string _windowTitle; /**< Stores the title of the window           */
        bool _isFullScreen;       /**< Tells if the window is fullscreen or not */

        SDL_Surface* _surface;           /**< Stores the drawing surface                */
        Uint32 _sdlFlags;                /**< Stores the drawing surface's capabilities */
        std::list<Vector2> _resolutions; /**< Stores supported display resolutions      */

        EventListener _events; /**< The display's event listener              */
};


} /* namespace lavish */


#endif	/* DISPLAY_HPP */

