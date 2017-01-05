//
// Created by Kraghan on 21/12/2016.
//

#include <iostream>
#include "../../Header/Room/Room.hpp"
#include "../../Header/PhysicEngine/PhysicEngine.hpp"
#include "../../Header/GraphicEngine/GraphicEngine.hpp"

/* Explicit */ Room::Room()
{

}

/* Virtual */ Room::~Room()
{

}

Room::Room(unsigned width, unsigned height, bool isBossRoom)
{
    m_isBossRoom = isBossRoom;
    m_dimension = sf::Vector2u(width,height);

    PhysicObjects* wallTop = PhysicEngine::Instance()->getPhysicObject();

    // Todo
    wallTop->initAsCollider(sf::Vector2f(0.0f,0.0f),
                            GraphicEngine::Instance()->getSpriteSize
                                    (sf::Vector2f(1600.0f,60.0f)));
    addPhysicObjects(wallTop);
    PhysicObjects* wallBottom = PhysicEngine::Instance()->getPhysicObject();
    wallBottom->initAsCollider(GraphicEngine::Instance()->getSpriteSize
                                       (sf::Vector2f(0.0f,800.0f)),
                               GraphicEngine::Instance()->getSpriteSize
                                       (sf::Vector2f(1600.0f,160.0f)));

    addPhysicObjects(wallBottom);

    PhysicObjects* wallLeft = PhysicEngine::Instance()->getPhysicObject();
    wallLeft->initAsCollider(sf::Vector2f(0.0f,0.0f),
                     GraphicEngine::Instance()->getSpriteSize
                             (sf::Vector2f(160.0f,960.0f)));
    PhysicObjects* wallRight = PhysicEngine::Instance()->getPhysicObject();
    addPhysicObjects(wallLeft);
    wallRight->initAsCollider(GraphicEngine::Instance()->getSpriteSize
                                      (sf::Vector2f(1600.0f-160.0f,0.0f)),
                              GraphicEngine::Instance()->getSpriteSize
                                      (sf::Vector2f(160.0f,960.0f)));
    addPhysicObjects(wallRight);
}

void Room::display()
{
    for(auto sprite : m_apsprites)
    {
        sprite->setVisible(true);
    }

    for(auto object : m_apphysicObjects)
    {
        object->setActive();
    }
}

void Room::hide()
{
    for(auto sprite : m_apsprites)
    {
        sprite->setVisible(false);
    }

    for(auto object : m_apphysicObjects)
    {
        object->setInactive();
    }
}

unsigned Room::getWidth()
{
    return m_dimension.x*standardWidth;
}

unsigned Room::getHeight()
{
    return m_dimension.y*standardHeight;
}

void Room::addSprite(Sprite* sprite)
{
    m_apsprites.push_back(sprite);
}

void Room::addPhysicObjects(PhysicObjects* object)
{
    m_apphysicObjects.push_back(object);
}

void Room::addObstacle(sf::Vector2f position)
{
    // Add physic
    PhysicObjects* object = PhysicEngine::Instance()->getPhysicObject();
    object->initAsCollider(position,sf::Vector2f(80.0f,80.0f));
    addPhysicObjects(object);

    // Add graphic
    Sprite* sprite = GraphicEngine::Instance()->getSprite();
    sprite->setPosition(position);
    sprite->setTexture(*GraphicEngine::Instance()->getTextures("OBSTACLE"));
}
