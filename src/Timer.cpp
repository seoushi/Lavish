/* 
 * File:   timer.cpp
 * Author: Sean Chapel
 * 
 * Created on May 29, 2009, 2:22 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include "Timer.hpp"
#include "Platform.hpp"


namespace lavish
{


Timer::Timer()
{
    interval = 0;
    Reset();
}


Timer::Timer(unsigned int interval)
{
    this->interval = interval;
    Reset();
}


Timer::~Timer()
{
}


void Timer::SetInterval(unsigned int interval)
{
    Reset();
}


void Timer::Reset()
{
    lastTime = GetCurrentGameTime();
}


bool Timer::IsTimeUp()
{
    return (GetCurrentGameTime() - lastTime) >= interval;
}


unsigned int Timer::GetCurrentGameTime()
{
    return SDL_GetTicks();
}


} /* lavish */

