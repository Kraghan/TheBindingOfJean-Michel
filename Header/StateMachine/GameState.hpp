//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_GAMESTATE_HPP
#define BINDINGOFJEANMICHEL_GAMESTATE_HPP


#include "State.hpp"
#include "../Tools/Singleton.hpp"
#include "../../Header/GraphicEngine/GraphicEngine.hpp"
#include "../Level/Level.hpp"
#include "../Player/Player.hpp"
#include <SFML/System.hpp>

class GameState : public State, public Singleton <GameState>
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            GameState              ();
    virtual             ~GameState             ();
    virtual bool        onEnter                ();
    virtual bool        onExit                 ();
    virtual void        onPollEvent            (sf::Event e);
    void                init                   ();
    virtual void        update                 (double dt);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    Level               m_level;
    Room*               m_activeRoom;
    Player              m_player;
};

#endif //BINDINGOFJEANMICHEL_GAMESTATE_HPP
