//
// Created by Kraghan on 23/12/2016.
//

#include <iostream>
#include <math.h>
#include "../../Header/PhysicEngine/PhysicObjects.hpp"

/* Explicit */ PhysicObjects::PhysicObjects()
: m_isUsed(false)
, m_isReady(false)
, m_isCollider(false)
, m_isRigidBody(false)
, m_triggerAction()
, m_position(0.0f,0.0f)
, m_dimension(0.0f,0.0f)
, m_velocity(0.0f,0.0f)
, m_maxSpeed(0.0f)
, m_acceleration(0.0f)
, m_isMovingLeft(false)
, m_isMovingRight(false)
, m_isMovingUp(false)
, m_isMovingDown(false)
, m_blockMovingLeft(false)
, m_blockMovingRight(false)
, m_blockMovingUp(false)
, m_blockMovingDown(false)
, m_active(false)
{
    // None
}

/* Virtual */ PhysicObjects::~PhysicObjects()
{
    // None
}

void PhysicObjects::initAsCollider(sf::Vector2f position, sf::Vector2f dimension)
{
    m_isReady = true;
    m_isCollider = true;
    m_active = false;
    m_isRigidBody = false;
    m_triggerAction = nullptr;
    m_position = position;
    m_dimension = dimension;
    m_velocity = sf::Vector2f(0.0f,0.0f);
    m_maxSpeed = 0.0f;
    m_acceleration = 0.0f;
}

void PhysicObjects::initAsRigidBody(sf::Vector2f position, float maxSpeed, float acceleration)
{
    m_isReady = true;
    m_isCollider = false;
    m_active = false;
    m_isRigidBody = true;
    m_triggerAction = nullptr;
    m_position = position;
    m_dimension = sf::Vector2f(0.0f,0.0f);
    m_velocity = sf::Vector2f(0.0f,0.0f);
    m_maxSpeed = maxSpeed;
    m_acceleration = acceleration;
}

void PhysicObjects::initAsMovingCollider(sf::Vector2f position, sf::Vector2f dimension,
                                         float maxSpeed, float acceleration)
{
    m_isReady = true;
    m_isCollider = true;
    m_active = false;
    m_isRigidBody = true;
    m_triggerAction = nullptr;
    m_position = position;
    m_dimension = dimension;
    m_velocity = sf::Vector2f(0.0f,0.0f);
    m_maxSpeed = maxSpeed;
    m_acceleration = acceleration;
}

void PhysicObjects::initAsTrigger(sf::Vector2f position, sf::Vector2f dimension, TriggerAction* action)
{
    m_isReady = true;
    m_isCollider = false;
    m_active = false;
    m_isRigidBody = false;
    m_triggerAction = action;
    m_position = position;
    m_dimension = dimension;
    m_velocity = sf::Vector2f(0.0f,0.0f);
    m_maxSpeed = 0.0f;
    m_acceleration = 0.0f;
}

void PhysicObjects::startMoveLeft()
{
    m_isMovingLeft = true;
}

void PhysicObjects::startMoveRight()
{
    m_isMovingRight = true;
}

void PhysicObjects::startMoveDown()
{
    m_isMovingDown = true;
}

void PhysicObjects::startMoveUp()
{
    m_isMovingUp = true;
}

void PhysicObjects::stopMoveLeft()
{
    m_isMovingLeft = false;
}

void PhysicObjects::stopMoveRight()
{
    m_isMovingRight = false;
}

void PhysicObjects::stopMoveDown()
{
    m_isMovingDown = false;
}

void PhysicObjects::stopMoveUp()
{
    m_isMovingUp = false;
}

bool PhysicObjects::isMovingLeft()
{
    return m_isMovingLeft;
}

bool PhysicObjects::isMovingRight()
{
    return m_isMovingRight;
}

bool PhysicObjects::isMovingDown()
{
    return m_isMovingDown;
}

bool PhysicObjects::isMovingUp()
{
    return m_isMovingUp;
}

bool PhysicObjects::isUsed()
{
    return m_isUsed;
}

bool PhysicObjects::isReady()
{
    return m_isReady;
}

bool PhysicObjects::isRigidBody()
{
    return m_isRigidBody;
}

bool PhysicObjects::isCollider()
{
    return m_isCollider;
}

bool PhysicObjects::isTrigger()
{
    return m_triggerAction != nullptr;
}


/* Static */ void PhysicObjects::release(PhysicObjects *&object)
{
    // There is no points to try to
    // release a null pointer
    if(object == nullptr) return;

    // The game doesn't own this
    object->setFree();

    // Setting the pointer to nullptr
    object = nullptr;
}

void PhysicObjects::update(double dt)
{
    if(!m_isRigidBody)
        return;

    sf::Vector2f newVelocity = m_velocity;

    // Slow
    if(!m_isMovingLeft && m_velocity.x < 0)
    {
        newVelocity.x -= (m_velocity.x*coeffFriction)*dt;
    }
    if(!m_isMovingRight && m_velocity.x > 0)
    {
        newVelocity.x -= (m_velocity.x*coeffFriction)*dt;
    }
    if(!m_isMovingUp && m_velocity.y < 0)
    {
        newVelocity.y -= (m_velocity.y*coeffFriction)*dt;
    }
    if(!m_isMovingDown && m_velocity.y > 0)
    {
        newVelocity.y -= (m_velocity.y*coeffFriction)*dt;
    }

    if(fabsf(newVelocity.x) < 1.0f)
        newVelocity.x = 0.0;
    if(fabsf(newVelocity.y) < 1.0f)
        newVelocity.y = 0.0;

    // Update acceleration
    if(m_isMovingDown && !m_blockMovingDown) {
        newVelocity.y += m_acceleration * dt;
    }
    else if(m_isMovingUp && !m_blockMovingUp) {
        newVelocity.y -= m_acceleration * dt;
    }
    if(m_isMovingLeft && !m_blockMovingLeft) {
        newVelocity.x -= m_acceleration * dt;
    }
    else if(m_isMovingRight && !m_blockMovingRight) {
        newVelocity.x += m_acceleration * dt;
    }
    if(fabsf(newVelocity.x) <= m_maxSpeed)
        m_velocity.x = newVelocity.x;
    else
        if(newVelocity.x > 0)
            m_velocity.x = m_maxSpeed;
        else
            m_velocity.x = -m_maxSpeed;
    if(fabsf(newVelocity.y) <= m_maxSpeed)
        m_velocity.y = newVelocity.y;
    else
        if(newVelocity.y > 0)
            m_velocity.y = m_maxSpeed;
        else
            m_velocity.y = -m_maxSpeed;

    // Update position
    m_position += sf::Vector2f((float) (m_velocity.x * dt), (float) (m_velocity.y * dt));
}

sf::Vector2f PhysicObjects::getPosition()
{
    return m_position;
}

sf::Vector2f PhysicObjects::getDimension()
{
    return m_dimension;
}

sf::Vector2f PhysicObjects::isColliding(PhysicObjects *object)
{
    float d1x = object->getPosition().x - (m_position.x + m_dimension.x);
    float d1y = object->getPosition().y - (m_position.y + m_dimension.y);

    if (d1x > 0.0f || d1y > 0.0f)
        return sf::Vector2f(0.0f,0.0f);

    float d2x = m_position.x - (object->getPosition().x +
                                object->getDimension().x);
    float d2y = m_position.y - (object->getPosition().y +
                                object->getDimension().y);

    if (d2x > 0.0f || d2y > 0.0f)
        return sf::Vector2f(0.0f,0.0f);

    sf::Vector2f deep = sf::Vector2f(0.0f,0.0f);

    if(d1x > d2x && d1x > d1y && d1x > d2y)
        deep.x = d1x;
    if(d2x > d1x && d2x > d1y && d2x > d2y)
        deep.x = d2x;
    if(d1y > d2x && d1y > d1x && d1y > d2y)
        deep.y = d1y;
    if(d2y > d1x && d2y > d2x && d2y > d1y)
        deep.y = d2y;
    return deep;
}


void PhysicObjects::setActive()
{
    m_active = true;
}

void PhysicObjects::setInactive()
{
    m_active = false;
}

bool PhysicObjects::isActive()
{
    return m_active;
}

void PhysicObjects::blockMovingLeft(bool value)
{
    m_blockMovingLeft = value;
}

void PhysicObjects::blockMovingRight(bool value)
{
    m_blockMovingRight = value;
}

void PhysicObjects::blockMovingDown(bool value)
{
    m_blockMovingDown = value;
}

void PhysicObjects::blockMovingUp(bool value)
{
    m_blockMovingUp = value;
}

void PhysicObjects::killVerticalKinetic()
{
    m_velocity.y = 0.0f;
}

void PhysicObjects::killHorizontalKinetic()
{
    m_velocity.x = 0.0f;
}