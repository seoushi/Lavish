/* 
 * File:   eventListener.hpp
 * Author: Sean Chapel
 *
 * Created on May 27, 2009, 12:56 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _EVENT_LISTENER_HPP
#define	_EVENT_LISTENER_HPP

#include <list>
#include <memory>

#include <lavish/core/mouse.hpp>
#include <lavish/core/keyboard.hpp>

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
        bool Update();

        /**
         * Adds a listener that will receive events
         * @param listener the mouse event listener
         */
        void AttachMouseListener(std::shared_ptr<MouseListener> listener);

        /**
         * Removes a listener from receiving events
         * @param listener the mouse event listener
         */
        void DetachMouseListener(std::shared_ptr<MouseListener> listener);

        /**
         * Adds a listener that will receive events
         * @param listener the keyboard event listener
         */
        void AttachKeyboardListener(std::shared_ptr<KeyboardListener> listener);

        /**
         * Removes a listener from receiving events
         * @param listener the keyboard event listener
         */
        void DetachKeyboardListener(std::shared_ptr<KeyboardListener> listener);

    private:

        std::list<std::shared_ptr<MouseListener>>       mouseListeners;    /**< All attached mouse listeners       */
        std::list<std::shared_ptr<KeyboardListener>>    keyboardListeners; /**< All attached keyboard listeners    */

};


}/* namespace lavish */

#endif	/* _EVENT_LISTENER_HPP */


