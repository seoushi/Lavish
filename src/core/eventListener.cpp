/* 
 * File:   eventListener.cpp
 * Author: Sean Chapel
 * 
 * Created on May 27, 2009, 12:56 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#include <algorithm>

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
				std::for_each(begin(mouseListeners), end(mouseListeners), [&e](std::shared_ptr<MouseListener> itr)
					{
						itr->OnButtonDown((mouse::Button) e.button.button);
					});
                break;

            case SDL_MOUSEBUTTONUP:
				std::for_each(begin(mouseListeners), end(mouseListeners), [&e](std::shared_ptr<MouseListener> itr)
					{
						itr->OnButtonUp((mouse::Button) e.button.button);
					});
                break;
                
            case SDL_MOUSEMOTION:
				std::for_each(begin(mouseListeners), end(mouseListeners), [&e](std::shared_ptr<MouseListener> itr)
					{
						itr->OnMouseMove(e.motion.x, e.motion.y, e.motion.xrel, e.motion.yrel);
					});
                break;

            case SDL_KEYDOWN:
				std::for_each(begin(keyboardListeners), end(keyboardListeners), [&e](std::shared_ptr<KeyboardListener> itr)
					{
						itr->OnKeyDown( (keyboard::Key) e.key.keysym.sym );
					});
                break;

            case SDL_KEYUP:
				std::for_each(begin(keyboardListeners), end(keyboardListeners), [&e](std::shared_ptr<KeyboardListener> itr)
					{
						itr->OnKeyUp( (keyboard::Key) e.key.keysym.sym );
					});
                break;
        }
    }

    return true;
}


void EventListener::AttachMouseListener(std::shared_ptr<MouseListener> listener)
{
    mouseListeners.push_back(listener);
}


void EventListener::DetachMouseListener(std::shared_ptr<MouseListener> listener)
{
    mouseListeners.remove(listener);
}


void EventListener::AttachKeyboardListener(std::shared_ptr<KeyboardListener> listener)
{
    keyboardListeners.push_back(listener);
}


void EventListener::DetachKeyboardListener(std::shared_ptr<KeyboardListener> listener)
{
    keyboardListeners.remove(listener);
}


} /* namespace lavish */

