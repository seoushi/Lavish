/* 
 * File:   stateManager.cpp
 * Author: seanc
 *
 * Created on June 10, 2009, 2:17 AM
 */


#include "StateManager.hpp"
#include "GameState.hpp"
#include "Timer.hpp"

namespace lavish
{

StateManager::StateManager(Display* display)
{
    this->display = display;
    isRunning = false;
    currentState = NULL;
}


StateManager::~StateManager()
{
    if(currentState)
    {
        delete currentState;
    }
}


void StateManager::ChangeState(GameState* state)
{
    if(currentState)
    {
        delete currentState;
        currentState = NULL;
    }

    if(state)
    {
        state->display = display;
        state->stateManager = this;
        
        state->OnLoad();
        currentState = state;
    }
}


void StateManager::Run()
{
    unsigned int lastFrameTime = Timer::GetCurrentGameTime();
    unsigned int deltaTime;

    while(isRunning && currentState)
    {
        deltaTime = Timer::GetCurrentGameTime() - lastFrameTime;
        lastFrameTime = Timer::GetCurrentGameTime();

        display->listener()->update();

        currentState->OnUpdate( deltaTime );
        currentState->OnRender();
    }
}


void StateManager::Stop()
{
    isRunning = false;
}


} /* lavish */

