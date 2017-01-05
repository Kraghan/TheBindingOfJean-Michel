//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_GAME_HPP
#define BINDINGOFJEANMICHEL_GAME_HPP


#include "../Tools/Updatable.hpp"
#include "../StateMachine/StateMachine.hpp"
#include "../StateMachine/GameState.hpp"
#include "../StateMachine/MenuState.hpp"

class Game : public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Game              ();
    virtual             ~Game             ();
    void                init              ();
    virtual void        update            (double dt);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //BINDINGOFJEANMICHEL_GAME_HPP
