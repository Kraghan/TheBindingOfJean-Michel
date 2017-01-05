//
// Created by Kraghan on 22/12/2016.
//

#include "../../Header/Player/Player.hpp"

/* Explicit */ Player::Player()
: AnimatedEntity()
{
    // Initialize graphic
    m_sprite = GraphicEngine::Instance()->getSprite();
    if(m_sprite == nullptr)
    {
        std::cerr << "Can't get player sprite" << std::endl;
        return;
    }
    sf::Texture *texturePlayer = GraphicEngine::Instance()->getTextures("PLAYER");
    m_sprite->setTexture(*texturePlayer);
    m_sprite->setTextureRect(sf::IntRect(0,0,160,160));

    // Initialize animations
    m_animation.addState("IDLE",   AnimationState());
    m_animation.addState("RLEFT",  AnimationState());
    m_animation.addState("RRIGHT", AnimationState());
    m_animation.setState("IDLE");

    m_animation.getState("IDLE")->init(
            m_sprite, true,
            sf::Vector2i(0, 0), sf::Vector2i(160, 160),
            160, 1, 0.08);

    m_animation.getState("RLEFT")->init(
            m_sprite, true,
            sf::Vector2i(0, 160), sf::Vector2i(160, 160),
            160, 4, 0.08);

    m_animation.getState("RRIGHT")->init(
            m_sprite, true,
            sf::Vector2i(0, 320), sf::Vector2i(160, 160),
            160, 4, 0.08);

    // Set initial state
    m_animation.setState("IDLE");
    m_animation.start();
}

/* Virtual */ Player::~Player()
{

}

void Player::update(double dt)
{
    m_sprite->setPosition(getPhysicObject()->getPosition());
}

void Player::init()
{
    Entity::init(10,sf::Vector2f(GraphicEngine::Instance()->getResolution().x/2,
                                 GraphicEngine::Instance()->getResolution().y/2),
                 sf::Vector2f(160,160),500.0f,1000.0f);
    activePhysic();
}

