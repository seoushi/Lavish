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

#include <lavish/core/display.hpp>

using namespace std;

namespace lavish
{


Display::Display()
{
    isFullScreen = false;
    surface = NULL;
}

Display::~Display()
{
}

bool Display::Initialize(int Width, int Height, int Bpp, std::string WindowTitle, bool resizable)
{
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        cout << "Unable to initialize the Graphics Layer: " << SDL_GetError() << endl;
        return false;
    }

    this->width = Width;
    this->height = Height;
    this->bpp = Bpp;
    this->windowTitle = WindowTitle;


    sdlFlags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE;

    if(resizable)
    {
        sdlFlags = sdlFlags | SDL_RESIZABLE;
    }

    isFullScreen = false;


    //setup flags
    const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();

    if (videoInfo->hw_available)
    {
        sdlFlags |= SDL_HWSURFACE;
    }
    else
    {
        sdlFlags |= SDL_SWSURFACE;
    }
    // This checks if hardware blits can be done
    if ( videoInfo->blit_hw )
    {
        sdlFlags |= SDL_HWACCEL;
    }


    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );


    atexit(SDL_Quit);


    cout << "Supported Resolutions" << endl << "---------------------" << endl;

    SDL_Rect** modes;
    modes = SDL_ListModes(videoInfo->vfmt, sdlFlags | SDL_FULLSCREEN);

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

            resolutions.push_back( Vector2(rect->w, rect->h) );

            i++;
        }
    }

	return true;
}

std::list<Vector2> Display::DisplayModes()
{
    return resolutions;
}

void Display::ClearColor(Color c)
{
    glClearColor( c.R(), c.G(), c.B(), c.A() );
}

void Display::ClearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::SwapBuffers()
{
    SDL_GL_SwapBuffers();
}

bool Display::Show()
{

    //create the surface
    surface = SDL_SetVideoMode(width, height, bpp, sdlFlags);

    if ( surface == NULL)
    {
        cout << "Video mode set failed: " << SDL_GetError() << endl;
        return false;
    }

    //set the window title
    SDL_WM_SetCaption(windowTitle.c_str(), NULL);

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

bool Display::Resize(int width, int height)
{
    // Protect against a divide by zero
    if ( height == 0 )
    {
        height = 1;
    }

    //resize sdl surface
    surface = SDL_SetVideoMode( width, height, bpp, sdlFlags );

    if (surface == NULL)
    {
        cout << "Could not get a surface after resize: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

void Display::ToggleFullScreen()
{
    isFullScreen = !isFullScreen;


    if(surface != NULL)
    {
        SDL_WM_ToggleFullScreen(surface);

        if (!isFullScreen)
        {
            SDL_ShowCursor(SDL_ENABLE);
        }
        else
        {
            SDL_ShowCursor(SDL_DISABLE);
        }
    }
}

int Display::Width()
{
    return width;
}

int Display::Height()
{
    return height;
}

void Display::SetupPerspective(float angle, float near, float far)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, width / height, near, far);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_BLEND);
}

void Display::Setup2d()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 0, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // some sane defaults
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


EventListener* Display::Listener()
{
    return &events;
}


} /* namespace lavish */

