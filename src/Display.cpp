/*
 * File:   display.cpp
 * Author: Sean Chapel
 *
 * Created on May 26, 2009, 11:38 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 *
 */

#include <iostream>
#include <dlfcn.h>

#include "Display.hpp"

using namespace std;

namespace lavish
{


Display::Display()
{
    _width = 0;
    _height = 0;
    _bpp = 0;
    _windowTitle = "";
    _sdlFlags = 0;
    _isFullScreen = false;
    _surface = NULL;
}


Display::~Display()
{
}


bool Display::init(int Width, int Height, int Bpp, std::string WindowTitle, bool resizable)
{
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        cout << "Unable to initialize the Graphics Layer: " << SDL_GetError() << endl;
        return false;
    }

    _width = Width;
    _height = Height;
    _bpp = Bpp;
    _windowTitle = WindowTitle;


    _sdlFlags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE;

    if(resizable)
    {
        _sdlFlags = _sdlFlags | SDL_RESIZABLE;
    }

    _isFullScreen = false;


    //setup flags
    const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();

    if (videoInfo->hw_available)
    {
        _sdlFlags |= SDL_HWSURFACE;
    }
    else
    {
        _sdlFlags |= SDL_SWSURFACE;
    }
    // This checks if hardware blits can be done
    if ( videoInfo->blit_hw )
    {
        _sdlFlags |= SDL_HWACCEL;
    }


    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );


    atexit(SDL_Quit);


    cout << "Supported Resolutions" << endl << "---------------------" << endl;

    SDL_Rect** modes;
    modes = SDL_ListModes(videoInfo->vfmt, _sdlFlags | SDL_FULLSCREEN);

    if(modes == (SDL_Rect **)0)
    {
	 cout << "No modes available!" << endl;
    }
    else if(modes == (SDL_Rect **)-1)
    {
	 cout << "All resolutions available." << endl;
    }
    else
    {
        unsigned int i = 0;
        while(modes[i] > 0)
        {
            SDL_Rect* rect = modes[i];

            cout << rect->w << "x" << rect->h << endl;

            _resolutions.push_back( Vector2(rect->w, rect->h) );

            i++;
        }
    }

	return true;
}


std::list<Vector2> Display::displayModes()
{
    return _resolutions;
}


void Display::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Display::swapBuffers()
{
    SDL_GL_SwapBuffers();
}


bool Display::show()
{

    //create the surface
    _surface = SDL_SetVideoMode(_width, _height, _bpp, _sdlFlags);

    if ( _surface == NULL)
    {
        cout << "Video mode set failed: " << SDL_GetError() << endl;
        return false;
    }

    //set the window title
    SDL_WM_SetCaption(_windowTitle.c_str(), NULL);

    GLenum err = glewInit();
    if(GLEW_OK != err)
    {
        cout << "Error: " << glewGetErrorString(err) << endl;
        return false;
    }

    if(!GLEW_VERSION_1_5)
    {
        cout << "Error: Your video card does not support OpenGL 1.5." << endl;
        return false;
    }

    return true;
}

bool Display::resize(int width, int height)
{
    // Protect against a divide by zero
    if ( height == 0 )
    {
        height = 1;
    }

    //resize sdl surface
    _surface = SDL_SetVideoMode( _width, _height, _bpp, _sdlFlags );

    if (_surface == NULL)
    {
        cout << "Could not get a surface after resize: " << SDL_GetError() << endl;
        return false;
    }

    _width = width;
    _height = height;

    return true;
}

void Display::toggleFullScreen()
{
    _isFullScreen = !_isFullScreen;


    if(_surface != NULL)
    {
        SDL_WM_ToggleFullScreen(_surface);

        if (!_isFullScreen)
        {
            SDL_ShowCursor(SDL_ENABLE);
        }
        else
        {
            SDL_ShowCursor(SDL_DISABLE);
        }
    }
}

int Display::width()
{
    return _width;
}

int Display::height()
{
    return _height;
}

void Display::setupPerspective(float angle, float near, float far)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, _width / _height, near, far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_BLEND);
}

void Display::setup2d()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, _width, 0.0f, _height, 0, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // some sane defaults
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


EventListener* Display::listener()
{
    return &_events;
}


void Display::showMouseCursor(bool isShown)
{
	SDL_ShowCursor(isShown);
}


void Display::grabInput(bool shouldGrabInput)
{
	if(shouldGrabInput)
	{
		SDL_WM_GrabInput(SDL_GRAB_ON);
	}
	else
	{
		SDL_WM_GrabInput(SDL_GRAB_OFF);
	}
}

} /* namespace lavish */

