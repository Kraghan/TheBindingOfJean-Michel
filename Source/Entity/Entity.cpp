//
// Created by Kraghan on 22/12/2016.
//

#include "../../Header/Entity/Entity.hpp"
#include "../../Header/PhysicEngine/PhysicEngine.hpp"

/* Explicit */ Entity::Entity()
: m_sprite(nullptr)
, m_physicObject(nullptr)
, m_hitPoint(0)
{
    // None
}

/* Virtual */ Entity::~Entity()
{

}

void Entity::setLife(int life)
{
    m_hitPoint = life;
}

void Entity::init(int life, sf::Vector2f position, sf::Vector2f dimension, float maxSpeed, float acceleration)
{
    m_hitPoint = life;
    m_physicObject = PhysicEngine::Instance()->getPhysicObject();
    m_physicObject->initAsMovingCollider(position,dimension,maxSpeed,acceleration);
}

PhysicObjects *Entity::getPhysicObject()
{
    return m_physicObject;
}

void Entity::activePhysic()
{
    m_physicObject->setActive();
}

void Entity::deactivePhysic()
{
    m_physicObject->setInactive();
}

void Entity::hit(unsigned damage)
{
    m_hitPoint -= damage;
}
