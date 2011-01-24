/* 
 * File:   EventListener.cpp
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
 */

#include "EventListener.hpp"
#include "Platform.hpp"


namespace lavish
{

EventListener::EventListener()
{
}

EventListener::~EventListener()
{
}

bool EventListener::update()
{
    SDL_Event e;

    while( SDL_PollEvent(&e) )
    {
        switch(e.type)
        {
            case SDL_QUIT:
                return false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                for(MouseListenerIterator itr = _mouseListeners.begin(); itr != _mouseListeners.end(); itr++)
                {
                    (*itr)->OnButtonDown((mouse::Button) e.button.button);
                }
                break;

            case SDL_MOUSEBUTTONUP:
                for(MouseListenerIterator itr = _mouseListeners.begin(); itr != _mouseListeners.end(); itr++)
                {
                    (*itr)->OnButtonUp((mouse::Button) e.button.button);
                }
                break;
                
            case SDL_MOUSEMOTION:
                for(MouseListenerIterator itr = _mouseListeners.begin(); itr != _mouseListeners.end(); itr++)
                {
                    (*itr)->OnMouseMove(e.motion.x, e.motion.y, e.motion.xrel, e.motion.yrel);
                }
                break;

            case SDL_KEYDOWN:
                for(KeyboardListenerIterator itr = _keyboardListeners.begin(); itr != _keyboardListeners.end(); itr++)
                {
                    (*itr)->OnKeyDown( (keyboard::Key) e.key.keysym.sym );
                }
                break;

            case SDL_KEYUP:
                for(KeyboardListenerIterator itr = _keyboardListeners.begin(); itr != _keyboardListeners.end(); itr++)
                {
                    (*itr)->OnKeyUp( (keyboard::Key) e.key.keysym.sym );
                }
                break;
        }
    }

    return true;
}


void EventListener::attachMouseListener(MouseListener* listener)
{
    _mouseListeners.push_back(listener);
}


void EventListener::detachMouseListener(MouseListener* listener)
{
    _mouseListeners.remove(listener);
}


void EventListener::attachKeyboardListener(KeyboardListener* listener)
{
    _keyboardListeners.push_back(listener);
}


void EventListener::detachKeyboardListener(KeyboardListener* listener)
{
    _keyboardListeners.remove(listener);
}


} /* namespace lavish */

