/* 
 * File:   stateManager.hpp
 * Author: Sean Chapel
 *
 * Created on June 10, 2009, 1:54 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _STATEMANAGER_HPP
#define	_STATEMANAGER_HPP

#include <lavish/core/display.hpp>
#include <lavish/core/platform.hpp>

namespace lavish
{

// avoid recursive header lookups
class GameState;

/**
 * A state manager used to handle game states
 */
class StateManager
{
    public:

        
        /**
         * A default constructor
         */
        StateManager(std::shared_ptr<Display> display);


        /**
         * Default destructor
         */
        ~StateManager();


        /**
         * Changes the current state to a new one
         * Destroyes the current state, loads the new one then changes to the new state
         */
        void ChangeState(std::shared_ptr<GameState> state);


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

        std::shared_ptr<Display> display;			/**< reference to the display               */
        bool isRunning;								/**< if the state manager is running or not */
        std::shared_ptr<GameState> currentState;	/**< holds the current state                */
};

} /* lavish */

#endif	/* _STATEMANAGER_HPP */

