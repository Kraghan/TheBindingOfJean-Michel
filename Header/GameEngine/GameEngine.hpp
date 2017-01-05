//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_GAMEENGINE_HPP
#define BINDINGOFJEANMICHEL_GAMEENGINE_HPP

#include "../../Header/StateMachine/StateMachine.hpp"
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "../GraphicEngine/GraphicEngine.hpp"
#include "../PhysicEngine/PhysicEngine.hpp"
#include "../../Header/Tools/SettingsParser.hpp"

class GameEngine : public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            GameEngine              ();
    virtual             ~GameEngine             ();
    void                init                    ();
    void                start                   ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    bool                m_isRunning;
    sf::RenderWindow*   m_window;
    const double        SECONDS_PER_UPDATE      = 1.0/120.0;
    Game                m_game;
    void                gameLoop                ();
    void                processInput            ();
    virtual void        update                  (double dt);
};


#endif //BINDINGOFJEANMICHEL_GAMEENGINE_HPP
