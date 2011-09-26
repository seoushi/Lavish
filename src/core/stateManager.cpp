/* 
 * File:   stateManager.cpp
 * Author: seanc
 *
 * Created on June 10, 2009, 2:17 AM
 */


#include <lavish/core/stateManager.hpp>
#include <lavish/core/gameState.hpp>
#include <lavish/core/timer.hpp>

namespace lavish
{

StateManager::StateManager(std::shared_ptr<Display> display)
{
    this->display = display;
    isRunning = false;
    currentState = NULL;
}


StateManager::~StateManager()
{
}


void StateManager::ChangeState(std::shared_ptr<GameState> state)
{
	if(state.get() != NULL)
    {
        state->display = display;
        state->stateManager = std::shared_ptr<StateManager>(this);
        
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

        display->Listener()->Update();

        currentState->OnUpdate( deltaTime );
        currentState->OnRender();
    }
}


void StateManager::Stop()
{
    isRunning = false;
}


} /* lavish */

