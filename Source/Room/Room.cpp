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

Room::Room(unsigned width, unsigned height)
{
    m_dimension = sf::Vector2u(width,height);
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

void Room::load()
{
    sf::Vector2f spriteSize = sf::Vector2f(GraphicEngine::Instance()->getResolution().x / Room::standardWidth,
                                           GraphicEngine::Instance()->getResolution().y / Room::standardHeight);

    for(unsigned x = 0; x < m_dimension.x; ++x)
    {
        for(unsigned y = 0; y < m_dimension.y; ++y)
        {
            Sprite* s = GraphicEngine::Instance()->getSprite();
            sf::Texture* texture = nullptr;
            if(x == 0)
            {
                if(y == 0)
                {
                    // Angle TL
                    texture = GraphicEngine::Instance()->getTextures("ANGLE_TL");
                }
                else if (y == Room::standardHeight-1)
                {
                    // Angle TR
                    texture = GraphicEngine::Instance()->getTextures("ANGLE_BL");
                }
                else
                {
                    // Wall texture top
                    texture = GraphicEngine::Instance()->getTextures("WALL_LEFT");
                }
            }
            else if(x == Room::standardWidth-1)
            {
                if(y == 0)
                {
                    // Angle BL
                    texture = GraphicEngine::Instance()->getTextures("ANGLE_TR");
                }
                else if (y == Room::standardHeight-1)
                {
                    // Angle BR
                    texture = GraphicEngine::Instance()->getTextures("ANGLE_BR");
                }
                else
                {
                    // Wall texture bottom
                    texture = GraphicEngine::Instance()->getTextures("WALL_RIGHT");
                }
            }
            else
            {
                if(y == 0)
                {
                    // Wall Left
                    texture = GraphicEngine::Instance()->getTextures("WALL_TOP");
                }
                else if (y == Room::standardHeight-1)
                {
                    // Wall Right
                    texture = GraphicEngine::Instance()->getTextures("WALL_BOTTOM");
                }
                else
                {
                    // Floor texture
                    //texture = GraphicEngine::Instance()->getTextures("");
                }
            }
            if(texture != nullptr)
            {
                s->setTexture(*texture);
                // To finish
                s->setPosition(x * spriteSize.x, y * spriteSize.y);
                addSprite(s);
            }
            else
            {
                Sprite::release(s);
            }
        }
    }

    // Add wall
    PhysicObjects* wallTop = PhysicEngine::Instance()->getPhysicObject();

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

bool Room::addNeighbour(NeighBourPosition pos, Room *room)
{
    switch (pos)
    {
        case NeighBourPosition::E_BOTTOM :
            if(m_bottomRoom == nullptr)
                m_bottomRoom = room;
            else
                return false;
            break;
        case NeighBourPosition::E_LEFT :
            if(m_leftRoom == nullptr)
                m_leftRoom = room;
            else
                return false;
            break;
        case NeighBourPosition::E_RIGHT :
            if(m_rightRoom == nullptr)
                m_rightRoom = room;
            else
                return false;
            break;
        case NeighBourPosition::E_TOP :
            if(m_topRoom == nullptr)
                m_topRoom = room;
            else
                return false;
            break;
        default:
            return false;
    }
    return true;
}