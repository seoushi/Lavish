/* 
 * File:   eventListener.cpp
 * Author: Sean Chapel
 * 
 * Created on May 27, 2009, 12:56 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <lavish/core/eventListener.hpp>
#include <lavish/core/platform.hpp>


namespace lavish
{

EventListener::EventListener()
{
}

EventListener::~EventListener()
{
}

bool EventListener::Update()
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
                for(MouseListenerIterator itr = mouseListeners.begin(); itr != mouseListeners.end(); itr++)
                {
                    (*itr)->OnButtonDown((mouse::Button) e.button.button);
                }
                break;

            case SDL_MOUSEBUTTONUP:
                for(MouseListenerIterator itr = mouseListeners.begin(); itr != mouseListeners.end(); itr++)
                {
                    (*itr)->OnButtonUp((mouse::Button) e.button.button);
                }
                break;
                
            case SDL_MOUSEMOTION:
                for(MouseListenerIterator itr = mouseListeners.begin(); itr != mouseListeners.end(); itr++)
                {
                    (*itr)->OnMouseMove(e.motion.x, e.motion.y, e.motion.xrel, e.motion.yrel);
                }
                break;

            case SDL_KEYDOWN:
                for(KeyboardListenerIterator itr = keyboardListeners.begin(); itr != keyboardListeners.end(); itr++)
                {
                    (*itr)->OnKeyDown( (keyboard::Key) e.key.keysym.sym );
                }
                break;

            case SDL_KEYUP:
                for(KeyboardListenerIterator itr = keyboardListeners.begin(); itr != keyboardListeners.end(); itr++)
                {
                    (*itr)->OnKeyUp( (keyboard::Key) e.key.keysym.sym );
                }
                break;
        }
    }

    return true;
}


void EventListener::AttachMouseListener(MouseListener* listener)
{
    mouseListeners.push_back(listener);
}


void EventListener::DetachMouseListener(MouseListener* listener)
{
    mouseListeners.remove(listener);
}


void EventListener::AttachKeyboardListener(KeyboardListener* listener)
{
    keyboardListeners.push_back(listener);
}


void EventListener::DetachKeyboardListener(KeyboardListener* listener)
{
    keyboardListeners.remove(listener);
}


} /* namespace lavish */

