/* 
 * File:   EventListener.hpp
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

#ifndef EVENT_LISTENER_HPP
#define	EVENT_LISTENER_HPP

#include <list>

#include "Mouse.hpp"
#include "Keyboard.hpp"

namespace lavish
{

/*
 * The event listener handles all input events
 * The proper way to get a reference to the event listener is from the Display class
 */
class EventListener
{
    public:

        /**
         * A default constructor
         */
        EventListener();

        /**
         * A default destructor
         */
        ~EventListener();

        /**
         * Polls for events and informs all attached listeners
         * @return if the windows has requested to be closed
         */
        bool update();

        /**
         * Adds a listener that will receive events
         * @param listener the mouse event listener
         */
        void attachMouseListener(MouseListener* listener);

        /**
         * Removes a listener from receiving events
         * @param listener the mouse event listener
         */
        void detachMouseListener(MouseListener* listener);

        /**
         * Adds a listener that will receive events
         * @param listener the keyboard event listener
         */
        void attachKeyboardListener(KeyboardListener* listener);

        /**
         * Removes a listener from receiving events
         * @param listener the keyboard event listener
         */
        void detachKeyboardListener(KeyboardListener* listener);

    private:

        std::list<MouseListener*>    _mouseListeners;    /**< All attached mouse listeners       */
        std::list<KeyboardListener*> _keyboardListeners; /**< All attached keyboard listeners    */

};


typedef std::list<MouseListener*>::iterator    MouseListenerIterator;      /**< A convenience define for interatoring over MouseListeners       */
typedef std::list<KeyboardListener*>::iterator KeyboardListenerIterator;   /**< A convenience define for interatoring over KeyboardListeners    */


}/* namespace lavish */

#endif	/* EVENT_LISTENER_HPP */


