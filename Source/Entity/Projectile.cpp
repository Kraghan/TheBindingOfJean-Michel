//
// Created by Kraghan on 10/01/2017.
//

#include "../../Header/Entity/Projectile.hpp"
/* Explicit */ Projectile::Projectile()
: m_timeToLive(0.0)
, m_damage(0)
, m_elapsed(0.0)
{

}

/* Virtual */ Projectile::~Projectile()
{

}

void Projectile::init(double timeToLive, unsigned damage, sf::Vector2f position,
                      sf::Vector2f dimension, sf::Vector2f speed)
{
    m_elapsed = 0.0;
    m_timeToLive = timeToLive;
    m_damage = damage;
    m_physicObject->initAsCollider(position,dimension);
    m_physicObject->impulse(speed.x,speed.y);
}

bool Projectile::isDead()
{
    return m_elapsed > m_timeToLive;
}

void Projectile::update(double dt)
{
    m_elapsed += dt;
}

