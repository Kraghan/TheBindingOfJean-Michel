//
// Created by Kraghan on 15/12/2016.
//

#include "../../Header/StateMachine/GameState.hpp"
#include "../../Header/Level/LevelGenerator.hpp"

/* explicit */ GameState::GameState()
: m_level()
, m_activeRoom(nullptr)
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
    Player::Instance()->init();
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
                if(!Player::Instance()->getPhysicObject()->isMovingUp())
                {
                    Player::Instance()->getPhysicObject()->startMoveUp();
                    Player::Instance()->getPhysicObject()->stopMoveDown();
                    Player::Instance()->startAnimation("WALK_BACK");
                }

                break;
            // D
            case sf::Keyboard::D :
                if(!Player::Instance()->getPhysicObject()->isMovingRight())
                {
                    Player::Instance()->getPhysicObject()->startMoveRight();
                    Player::Instance()->getPhysicObject()->stopMoveLeft();
                    Player::Instance()->startAnimation("WALK_RIGHT");
                }
                break;
            // Q
            case sf::Keyboard::Q :
                if(!Player::Instance()->getPhysicObject()->isMovingLeft())
                {
                    Player::Instance()->getPhysicObject()->startMoveLeft();
                    Player::Instance()->getPhysicObject()->stopMoveRight();
                    Player::Instance()->startAnimation("WALK_LEFT");
                }
                break;
            // S
            case sf::Keyboard::S :
                if(!Player::Instance()->getPhysicObject()->isMovingDown())
                {
                    Player::Instance()->getPhysicObject()->startMoveDown();
                    Player::Instance()->getPhysicObject()->stopMoveUp();
                    Player::Instance()->startAnimation("WALK_FRONT");
                }
                break;
            case sf::Keyboard::Up :
                Player::Instance()->setHeadOrientation(Position::E_TOP);
                Player::Instance()->shoot(Position::E_TOP);
                break;
            case sf::Keyboard::Down :
                Player::Instance()->setHeadOrientation(Position::E_BOTTOM);
                Player::Instance()->shoot(Position::E_BOTTOM);
                break;
            case sf::Keyboard::Left :
                Player::Instance()->setHeadOrientation(Position::E_LEFT);
                Player::Instance()->shoot(Position::E_LEFT);
                break;
            case sf::Keyboard::Right :
                Player::Instance()->setHeadOrientation(Position::E_RIGHT);
                Player::Instance()->shoot(Position::E_RIGHT);
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
                Player::Instance()->getPhysicObject()->stopMoveUp();
                if(!Player::Instance()->getPhysicObject()->isMovingDown() &&
                        !Player::Instance()->getPhysicObject()->isMovingLeft() &&
                        !Player::Instance()->getPhysicObject()->isMovingRight())
                    Player::Instance()->startAnimation("IDLE_BACK");
                break;
            // D
            case sf::Keyboard::D :
                Player::Instance()->getPhysicObject()->stopMoveRight();
                if(!Player::Instance()->getPhysicObject()->isMovingDown() &&
                   !Player::Instance()->getPhysicObject()->isMovingLeft() &&
                   !Player::Instance()->getPhysicObject()->isMovingUp())
                    Player::Instance()->startAnimation("IDLE_RIGHT");
                break;
            // Q
            case sf::Keyboard::Q :
                Player::Instance()->getPhysicObject()->stopMoveLeft();
                if(!Player::Instance()->getPhysicObject()->isMovingDown() &&
                   !Player::Instance()->getPhysicObject()->isMovingUp() &&
                   !Player::Instance()->getPhysicObject()->isMovingRight())
                    Player::Instance()->startAnimation("IDLE_LEFT");
                break;
            // S
            case sf::Keyboard::S :
                Player::Instance()->getPhysicObject()->stopMoveDown();
                if(!Player::Instance()->getPhysicObject()->isMovingUp() &&
                   !Player::Instance()->getPhysicObject()->isMovingLeft() &&
                   !Player::Instance()->getPhysicObject()->isMovingRight())
                    Player::Instance()->startAnimation("IDLE_FRONT");
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
    Player::Instance()->update(dt);
}
