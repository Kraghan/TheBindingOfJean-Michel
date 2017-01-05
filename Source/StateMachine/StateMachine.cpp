//
// Created by Kraghan on 15/12/2016.
//

#include "../../Header/StateMachine/StateMachine.hpp"

/* Explicit */ StateMachine::StateMachine()
{

}

/* Virtual */ StateMachine::~StateMachine()
{

}

/* virtual */ void StateMachine::update(double dt)
{
    // Updating only the last state
    if(!m_gameStates.empty()) m_gameStates.top()->update(dt);
}

void StateMachine::pushState(State * pState)
{
    // Pushing the state at the top of
    // State machine, calling onEnter()
    m_gameStates.push(pState);
    m_gameStates.top()->onEnter();
}

void StateMachine::changeState(State * pState)
{
    popState();
    pushState(pState);
}

void StateMachine::popState()
{
    // If the state machine isn't empty
    if(!m_gameStates.empty())
    {
        // If onExit succeed
        if(m_gameStates.top()->onExit())
        {
            // Removing the last state
            m_gameStates.pop();
        }
    }
}

State *StateMachine::activeState()
{
    return m_gameStates.top();
}
