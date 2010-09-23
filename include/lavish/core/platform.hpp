/* 
 * File:   platform.hpp
 * Author: Sean Chapel
 *
 * Created on May 26, 2009, 11:54 PM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _PLATFORM_HPP
#define	_PLATFORM_HPP


#ifdef __APPLE__
	#include <Lavish/misc/glew.h>
    #include <SDL/SDL.h>
    #include <SDL_image/SDL_image.h>
#else
    #include <GL/glew.h>
    #include <SDL/SDL.h>
    #include <SDL/SDL_image.h>
#endif


#endif	/* _PLATFORM_HPP */

