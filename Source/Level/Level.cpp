//
// Created by Kraghan on 21/12/2016.
//

#include "../../Header/Level/Level.hpp"

/* Explicit */ Level::Level()
{
    Room* r = RoomStorage::Instance()->getRandomRoom();

    sf::Vector2f spriteSize = sf::Vector2f(GraphicEngine::Instance()->getResolution().x / Room::standardWidth,
                                           GraphicEngine::Instance()->getResolution().y / Room::standardHeight);

    for(unsigned x = 0; x < r->getWidth(); ++x)
    {
        for(unsigned y = 0; y < r->getHeight(); ++y)
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
                r->addSprite(s);
            }
            else
            {
                Sprite::release(s);
            }
        }
    }
    m_aprooms.push_back(r);



}

/* Virtual */ Level::~Level()
{

}

Room *Level::getFirstRoom()
{
    return m_aprooms[0];
}
