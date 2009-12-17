/* 
 * File:   stateManager.hpp
 * Author: Sean Chapel
 *
 * Created on June 10, 2009, 1:54 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _STATEMANAGER_HPP
#define	_STATEMANAGER_HPP

#include <lavish/display.hpp>
#include <lavish/platform.hpp>

namespace lavish
{

// avoid recursive header lookups
class GameState;

/**
 * A state manager used to handle game states
 */
class LAVISH_DECLSPEC StateManager
{
    public:

        
        /**
         * A default constructor
         */
        StateManager(Display* display);


        /**
         * Default destructor
         */
        ~StateManager();


        /**
         * Changes the current state to a new one
         * Destroyes the current state, loads the new one then changes to the new state
         */
        void ChangeState(GameState* state);


        /**
         * Starts up the state manage into an infinite processing loop
         * Only exits out of loop when the current state is null or Stop has been called
         * @param display a reference to the display
         */
        void Run();


        /**
         * Stops the state manager
         * Does not rid of the current state, Calling run again will again like a resume
         */
        void Stop();
        

    protected:

        Display* display;        /**< reference to the display               */
        bool isRunning;          /**< if the state manager is running or not */
        GameState* currentState; /**< holds the current state                */
};

} /* lavish */

#endif	/* _STATEMANAGER_HPP */

