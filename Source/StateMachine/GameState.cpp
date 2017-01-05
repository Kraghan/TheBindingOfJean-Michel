//
// Created by Kraghan on 15/12/2016.
//

#include "../../Header/StateMachine/GameState.hpp"

/* explicit */ GameState::GameState()
: m_level()
, m_activeRoom(nullptr)
, m_player()
{

}

/* virtual */ GameState::~GameState()
{

}

/* virtual */ bool GameState::onEnter()
{
    m_level = Level();
    m_activeRoom = m_level.getFirstRoom();
    m_activeRoom->display();
    m_player = Player();
    m_player.init();
    return true;
}

/* virtual */ bool GameState::onExit()
{
    return true;
}

/* virtual */ void GameState::onPollEvent(sf::Event e)
{
    if(e.type == sf::Event::KeyPressed)
    {
        switch(e.key.code)
        {
            // Z
            case sf::Keyboard::Z :
                    m_player.getPhysicObject()->startMoveUp();
                    m_player.getPhysicObject()->stopMoveDown();
                break;
            // D
            case sf::Keyboard::D :
                    m_player.getPhysicObject()->startMoveRight();
                    m_player.getPhysicObject()->stopMoveLeft();
                break;
            // Q
            case sf::Keyboard::Q :
                    m_player.getPhysicObject()->startMoveLeft();
                    m_player.getPhysicObject()->stopMoveRight();
                break;
            // S
            case sf::Keyboard::S :
                    m_player.getPhysicObject()->startMoveDown();
                    m_player.getPhysicObject()->stopMoveUp();
                break;
            default:
                break;
        }
    }

    if(e.type == sf::Event::KeyReleased)
    {
        switch(e.key.code)
        {
            // Z
            case sf::Keyboard::Z :
                m_player.getPhysicObject()->stopMoveUp();
                break;
            // D
            case sf::Keyboard::D :
                m_player.getPhysicObject()->stopMoveRight();
                break;
            // Q
            case sf::Keyboard::Q :
                m_player.getPhysicObject()->stopMoveLeft();
                break;
            // S
            case sf::Keyboard::S :
                m_player.getPhysicObject()->stopMoveDown();
                break;
            default:
                break;
        }
    }
}

void GameState::init()
{

}

/* virtual */ void GameState::update(double dt)
{
    m_player.update(dt);
}
