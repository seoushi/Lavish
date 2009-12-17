/* 
 * File:   eventListener.hpp
 * Author: Sean Chapel
 *
 * Created on May 27, 2009, 12:56 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _EVENT_LISTENER_HPP
#define	_EVENT_LISTENER_HPP

#include <lavish/mouse.hpp>
#include <lavish/keyboard.hpp>
#include <list>

namespace lavish
{

/*
 * The event listener handles all input events
 * The proper way to get a reference to the event listener is from the Display class
 */
class LAVISH_DECLSPEC EventListener
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
        void AttachMouseListener(MouseListener* listener);

        /**
         * Removes a listener from receiving events
         * @param listener the mouse event listener
         */
        void DetachMouseListener(MouseListener* listener);

        /**
         * Adds a listener that will receive events
         * @param listener the keyboard event listener
         */
        void AttachKeyboardListener(KeyboardListener* listener);

        /**
         * Removes a listener from receiving events
         * @param listener the keyboard event listener
         */
        void DetachKeyboardListener(KeyboardListener* listener);

    private:

        std::list<MouseListener*>       mouseListeners;    /**< All attached mouse listeners       */
        std::list<KeyboardListener*>    keyboardListeners; /**< All attached keyboard listeners    */

};


typedef std::list<MouseListener*>::iterator     MouseListenerIterator;      /**< A convenience define for interatoring over MouseListeners       */
typedef std::list<KeyboardListener*>::iterator  KeyboardListenerIterator;   /**< A convenience define for interatoring over KeyboardListeners    */


}/* namespace lavish */

#endif	/* _EVENT_LISTENER_HPP */


