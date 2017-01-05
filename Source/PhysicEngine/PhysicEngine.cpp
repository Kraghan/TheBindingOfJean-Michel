//
// Created by Kraghan on 23/12/2016.
//

#include <iostream>
#include "../../Header/PhysicEngine/PhysicEngine.hpp"

/* Explicit */ PhysicEngine::PhysicEngine()
: m_aphysicObjects(nullptr)
, m_physicObjectsCount(0)
{
    // None
}

/* Virtual */ PhysicEngine::~PhysicEngine()
{
    delete[] m_aphysicObjects;
}

void PhysicEngine::update(double dt)
{

    for(unsigned i = 0; i < m_physicObjectsCount; ++i)
    {
        if(!m_aphysicObjects[i].isActive() || !m_aphysicObjects[i].isReady()
           || !m_aphysicObjects[i].isUsed())
            continue;

        PhysicObjects* object = &m_aphysicObjects[i];

        if(object->isRigidBody())
        {
            object->update(dt);

            if(object->isCollider())
            {
                processCollision(object);
            }
        }
    }
}

void PhysicEngine::init(unsigned physicObjectCount)
{
    delete[] m_aphysicObjects;
    m_aphysicObjects = new PhysicObjects[physicObjectCount];
    m_physicObjectsCount = physicObjectCount;
}

PhysicObjects *PhysicEngine::getPhysicObject()
{
    for(unsigned i = 0; i < m_physicObjectsCount; ++i)
    {
        if(!m_aphysicObjects[i].isUsed())
        {
            m_aphysicObjects[i].setUsed();
            return &m_aphysicObjects[i];
        }
    }
    return nullptr;
}

void PhysicEngine::processCollision(PhysicObjects* object)
{
    for(unsigned i = 0; i < m_physicObjectsCount; ++i)
    {
        if(!m_aphysicObjects[i].isActive() || !m_aphysicObjects[i].isUsed()
           || !m_aphysicObjects[i].isReady() || !m_aphysicObjects[i].isCollider()
           || &m_aphysicObjects[i] == object)
            continue;

        sf::Vector2f vector = object->isColliding(&m_aphysicObjects[i]);

        object->blockMovingUp(false);
        object->blockMovingDown(false);
        object->blockMovingLeft(false);
        object->blockMovingRight(false);

        if(vector != sf::Vector2f(0.0f,0.0f))
        {
            if(m_aphysicObjects[i].getPosition().y < object->getPosition().y
               && vector.y != 0.0f && object->m_velocity.y < 0.0f)
            {
                object->blockMovingUp(true);
                object->killVerticalKinetic();
                object->move(0.0f,-vector.y);
            }

            if(m_aphysicObjects[i].getPosition().y > object->getPosition().y
               && vector.y != 0.0f && object->m_velocity.y > 0.0f)
            {
                object->blockMovingDown(true);
                object->killVerticalKinetic();
                object->move(0.0f,vector.y);
            }

            if(m_aphysicObjects[i].getPosition().x < object->getPosition().x
               && vector.x != 0.0f && object->m_velocity.x < 0.0f)
            {
                object->blockMovingLeft(true);
                object->killHorizontalKinetic();
                object->move(-vector.x,0.0f);
            }

            if(m_aphysicObjects[i].getPosition().x > object->getPosition().x
               && vector.x != 0.0f && object->m_velocity.x > 0.0f)
            {
                object->blockMovingRight(true);
                object->killHorizontalKinetic();
                object->move(vector.x,0.0f);
            }
        }
    }
}
