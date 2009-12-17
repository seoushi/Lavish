/* 
 * File:   gameState.hpp
 * Author: Sean Chapel
 *
 * Created on June 10, 2009, 1:45 AM
 * Copyright 2009 Seoushi Games. All rights reserved.
 */

#ifndef _GAMESTATE_HPP
#define	_GAMESTATE_HPP

#include <lavish/display.hpp>
#include <lavish/stateManager.hpp>

namespace lavish
{


/**
* A Game State is used to manage a specific portion of a game
* Some examples are an intro screen, main menus, in-game
*/
class LAVISH_DECLSPEC GameState
{
    public:
        
        /**
         * Default constructor
         */
        GameState(){};

        
        /**
         * The destructor
         */
        virtual ~GameState(){};


        /**
         * Pure virtual function that is used to setup the game state
         */
        virtual void OnLoad() = 0;


        /**
         * Pure virtual function called every frame before rendering
         * @param timeElapsed the time since the last frame was called
         */
        virtual void OnUpdate(unsigned int timeElapsed) = 0;


        /**
         * Pure virtual function that renders the scene
         */
        virtual void OnRender() = 0;


        Display*      display;       /** holds a reference to the Display       */
        StateManager* stateManager;  /** holds a reference to the state manager */
};


    
} /* lavish */



#endif	/* _GAMESTATE_HPP */

