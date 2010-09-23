/* 
 * File:   display.hpp
 * Author: Sean Chapel
 *
 * Created on May 26, 2009, 11:38 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 *
 */

#ifndef _DISPLAY_HPP
#define	_DISPLAY_HPP

#include <string>
#include <list>

#include <lavish/core/platform.hpp>
#include <lavish/common/color.hpp>
#include <lavish/core/eventListener.hpp>
#include <lavish/math/vector2.hpp>

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
        bool Initialize(int Width = 640, int Height = 480, int Bpp = 32, std::string WindowTitle = "", bool resizable = false);
	
		/**
         * @return a list of known valid display modes
         * Requires that Display has been initialized
         */
        std::list<Vector2> DisplayModes();

        /*
         * Sets the clear color
         * @param c a Color
         */
        void ClearColor(Color c);

        /**
         * Clears the display
         */
        void ClearScreen();

        /**
         * Flips backbuffer to the display
         */
        void SwapBuffers();

        /**
         * Creates a window and shows it
         * Show() must be called before any graphics related functions are called
         * Initialize must be called before Show()
         * @return if the window was created correctly
         */
        bool Show();

        /**
         * Resizes the window
         * All data on the graphics card such as textures and models are not guarenteed to still be valid after the operation
         * @return if the window was resized correctly
         */
        bool Resize(int width, int height);

        /**
         * Toggles the display between windowed mode and fullscreen
         */
        void ToggleFullScreen();

        /**
         * Get the current width of the display
         * @return the width of the display
         */
        int Width();

        /**
         * Get the current height of the display
         * @return the height of the display
         */
        int Height();

        /**
         * A helper function to setup the display's perspective
         * @param angle the angle for the foc of the camera
         * @param near the near plane to render from
         * @param far the far plane to render to
         */
        void SetupPerspective(float angle, float near, float far);

        /**
         * A helper function to setup the display in 2d mode
         * Maps the screen by pixels
         * left is 0
         * right is the window's width
         * top is the window's height
         * bottom is 0
         * near and far are between 0 and 100
         */
        void Setup2d();

        /**
         * The event listener for the display
         * @return EventListener
         */
        EventListener* Listener();

    protected:

        int width;                  /**< Stores the width of the drawing area       */
        int height;                 /**< Stores the height of the drawing area      */
        int bpp;                    /**< Stores the bits per pixel of the screen    */
        std::string windowTitle;    /**< Stores the title of the window             */
        bool isFullScreen;          /**< Tells if the window is fullscreen or not   */

        SDL_Surface* surface;           /**< Stores the drawing surface                 */
        Uint32 sdlFlags;                /**< Stores the drawing surface's capabilities  */
        std::list<Vector2> resolutions; /**< Stores supported display resolutions       */

        EventListener events;       /**< The display's event listener               */
};


} /* namespace lavish */


#endif	/* _DISPLAY_HPP */

