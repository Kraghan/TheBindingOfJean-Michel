//
// Created by Kraghan on 15/12/2016.
//

#include "../../Header/GameEngine/Game.hpp"
#include "../../Header/Tools/RoomParser.hpp"

Game::Game()
{
    // None
}

Game::~Game()
{
    // None
}

void Game::init()
{
    time_t* t = new time_t();
    srand((unsigned)time(t));
    RoomParser parser = RoomParser();
    GameState::Instance()->init();
    MenuState::Instance()->init();
    StateMachine::Instance()->pushState(MenuState::Instance());
}

void Game::update(double dt)
{

}