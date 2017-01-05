//
// Created by Kraghan on 15/12/2016.
//

#include "../../Header/StateMachine/MenuState.hpp"
#include "../../Header/StateMachine/StateMachine.hpp"
#include "../../Header/StateMachine/GameState.hpp"


/* explicit */ MenuState::MenuState()
{

}

/* virtual */ MenuState::~MenuState()
{

}

/* virtual */ bool MenuState::onEnter()
{
    StateMachine::Instance()->pushState(GameState::Instance());
    return true;
}

/* virtual */ bool MenuState::onExit()
{
    return true;
}

/* virtual */ void MenuState::onPollEvent(sf::Event e)
{
    // None
}

void MenuState::init()
{

}

/* virtual */ void MenuState::update(double dt)
{

}
