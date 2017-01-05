//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_STATEMACHINE_HPP
#define BINDINGOFJEANMICHEL_STATEMACHINE_HPP

#include "State.hpp"
#include "../Tools/Singleton.hpp"
#include <stack>

class StateMachine : public Singleton < StateMachine >
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    /// Default constructor
    explicit            StateMachine            ();

    /// Default destructor
    virtual             ~StateMachine           ();

    /// Implements the update method
    virtual void        update                  (double dt);

    /// Push a state at the top of the state machine
    void                pushState               (State * pState);

    /// Remove the previous state before pushing another one
    void                changeState             (State * pState);

    /// Remove the state at the top of the state machine
    void                popState                ();

    /// Return a pointer on the active state
    State*              activeState             ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    std::stack <State*> m_gameStates;
};


#endif //BINDINGOFJEANMICHEL_STATEMACHINE_HPP
