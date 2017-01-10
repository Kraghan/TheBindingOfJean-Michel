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
    m_sprite->setTextureRect(sf::IntRect(0,0,80,80));

    // Initialize animations
    m_animation.addState("IDLE_FRONT", AnimationState());
    m_animation.addState("WALK_FRONT", AnimationState());
    m_animation.addState("IDLE_LEFT", AnimationState());
    m_animation.addState("WALK_LEFT", AnimationState());
    m_animation.addState("IDLE_RIGHT", AnimationState());
    m_animation.addState("WALK_RIGHT", AnimationState());
    m_animation.addState("IDLE_BACK", AnimationState());
    m_animation.addState("WALK_BACK", AnimationState());

    m_animation.setState("IDLE_FRONT");

    m_animation.getState("IDLE_FRONT")->init(
            m_sprite, true,
            sf::Vector2i(0, 0), sf::Vector2i(80, 80),
            80, 1, 0.08);

    m_animation.getState("IDLE_LEFT")->init(
            m_sprite, true,
            sf::Vector2i(0, 160), sf::Vector2i(80, 80),
            80, 1, 0.08);

    m_animation.getState("IDLE_RIGHT")->init(
            m_sprite, true,
            sf::Vector2i(0, 240), sf::Vector2i(80, 80),
            80, 1, 0.08);

    m_animation.getState("IDLE_BACK")->init(
            m_sprite, true,
            sf::Vector2i(0, 80), sf::Vector2i(80, 80),
            80, 1, 0.08);

    m_animation.getState("WALK_LEFT")->init(
            m_sprite, true,
            sf::Vector2i(80, 160), sf::Vector2i(80, 80),
            80, 2, 0.08);

    m_animation.getState("WALK_RIGHT")->init(
            m_sprite, true,
            sf::Vector2i(80, 240), sf::Vector2i(80, 80),
            80, 2, 0.08);

    m_animation.getState("WALK_FRONT")->init(
            m_sprite, true,
            sf::Vector2i(80, 0), sf::Vector2i(80, 80),
            80, 2, 0.08);

    m_animation.getState("WALK_BACK")->init(
            m_sprite, true,
            sf::Vector2i(80, 80), sf::Vector2i(80, 80),
            80, 2, 0.08);

    // Set initial state
    m_animation.setState("IDLE");
    m_animation.start();
}

/* Virtual */ Player::~Player()
{

}

void Player::update(double dt)
{
    m_animation.update(dt);
    m_sprite->setPosition(getPhysicObject()->getPosition());
}

void Player::init()
{
    Entity::init(10,sf::Vector2f(GraphicEngine::Instance()->getResolution()
                                         .x/2 - 40,
                                 GraphicEngine::Instance()->getResolution()
                                         .y/2 - 40),
                 sf::Vector2f(80,80),500.0f,1000.0f);
    activePhysic();
}

void Player::startAnimation(std::string name)
{
    if(m_animation.getState(name) != nullptr)
        m_animation.setState(name);
    else
        std::cerr<< "Animation not found" << std::endl;
}

