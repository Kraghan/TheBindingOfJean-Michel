//
// Created by Kraghan on 10/01/2017.
//

#include <iostream>
#include "../../Header/PhysicEngine/Trigger/ProjectileTrigger.hpp"

/* Explicit */ Projectile::Projectile()
: Entity()
, m_timeToLive(0.0)
, m_damage(0)
, m_elapsed(0.0)
, m_isFree(true)
{
    m_sprite = GraphicEngine::Instance()->getSprite();
    m_physicObject = PhysicEngine::Instance()->getPhysicObject();
}

/* Virtual */ Projectile::~Projectile()
{

}

void Projectile::init(double timeToLive, unsigned damage, sf::Vector2f position,
                      sf::Vector2f dimension, sf::Vector2f speed)
{
    m_isFree = false;
    m_elapsed = 0.0;
    m_timeToLive = timeToLive;
    m_damage = damage;
    float kinetic = speed.x != 0.0f ? fabsf(speed.x) : fabsf(speed.y);
    m_physicObject->initAsMovingTrigger(position,dimension,kinetic,0.0f,new ProjectileTrigger(this));
    m_physicObject->setActive();
    m_physicObject->impulse(speed.x,speed.y);
    if(speed.x > 0 )
        m_physicObject->startMoveRight();
    if(speed.x < 0 )
        m_physicObject->startMoveLeft();
    if(speed.y > 0 )
        m_physicObject->startMoveDown();
    if(speed.y < 0 )
        m_physicObject->startMoveUp();
}

bool Projectile::isDead()
{
    return m_elapsed > m_timeToLive;
}

void Projectile::update(double dt)
{
    if(!m_isFree)
    {
        m_elapsed += dt;
        m_sprite->setPosition(getPhysicObject()->getPosition());
        m_sprite->setVisible(!isDead());
    }
}

void Projectile::free()
{
    m_isFree = true;
    m_physicObject->setInactive();
    m_physicObject->stopMoveUp();
    m_physicObject->stopMoveDown();
    m_physicObject->stopMoveLeft();
    m_physicObject->stopMoveRight();
    m_sprite->setVisible(false);
}

bool Projectile::isFree()
{
    return m_isFree;
}

void Projectile::setTexture(sf::Texture* texture)
{
    m_sprite->setTexture(*texture);
}

void Projectile::kill()
{
    std::cout<< m_elapsed << " "  << m_timeToLive <<std::endl;
    m_elapsed = m_timeToLive;
    std::cout<< m_elapsed << " "  << m_timeToLive <<std::endl;
}

unsigned Projectile::getDamage()
{
    return m_damage;
}
