//
// Created by Kraghan on 15/12/2016.
//

#include "../../Header/StateMachine/GameState.hpp"
#include "../../Header/Level/LevelGenerator.hpp"

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
    LevelGenerator generator = LevelGenerator();
    m_level = generator.generateLevel(1);
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
                if(!m_player.getPhysicObject()->isMovingUp())
                {
                    m_player.getPhysicObject()->startMoveUp();
                    m_player.getPhysicObject()->stopMoveDown();
                    m_player.startAnimation("WALK_BACK");
                }

                break;
            // D
            case sf::Keyboard::D :
                if(!m_player.getPhysicObject()->isMovingRight())
                {
                    m_player.getPhysicObject()->startMoveRight();
                    m_player.getPhysicObject()->stopMoveLeft();
                    m_player.startAnimation("WALK_RIGHT");
                }
                break;
            // Q
            case sf::Keyboard::Q :
                if(!m_player.getPhysicObject()->isMovingLeft())
                {
                    m_player.getPhysicObject()->startMoveLeft();
                    m_player.getPhysicObject()->stopMoveRight();
                    m_player.startAnimation("WALK_LEFT");
                }
                break;
            // S
            case sf::Keyboard::S :
                if(!m_player.getPhysicObject()->isMovingDown())
                {
                    m_player.getPhysicObject()->startMoveDown();
                    m_player.getPhysicObject()->stopMoveUp();
                    m_player.startAnimation("WALK_FRONT");
                }
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
                if(!m_player.getPhysicObject()->isMovingDown() &&
                        !m_player.getPhysicObject()->isMovingLeft() &&
                        !m_player.getPhysicObject()->isMovingRight())
                    m_player.startAnimation("IDLE_BACK");
                break;
            // D
            case sf::Keyboard::D :
                m_player.getPhysicObject()->stopMoveRight();
                if(!m_player.getPhysicObject()->isMovingDown() &&
                   !m_player.getPhysicObject()->isMovingLeft() &&
                   !m_player.getPhysicObject()->isMovingUp())
                    m_player.startAnimation("IDLE_RIGHT");
                break;
            // Q
            case sf::Keyboard::Q :
                m_player.getPhysicObject()->stopMoveLeft();
                if(!m_player.getPhysicObject()->isMovingDown() &&
                   !m_player.getPhysicObject()->isMovingUp() &&
                   !m_player.getPhysicObject()->isMovingRight())
                    m_player.startAnimation("IDLE_LEFT");
                break;
            // S
            case sf::Keyboard::S :
                m_player.getPhysicObject()->stopMoveDown();
                if(!m_player.getPhysicObject()->isMovingUp() &&
                   !m_player.getPhysicObject()->isMovingLeft() &&
                   !m_player.getPhysicObject()->isMovingRight())
                    m_player.startAnimation("IDLE_FRONT");
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
