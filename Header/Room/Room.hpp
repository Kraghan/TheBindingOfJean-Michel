//
// Created by Kraghan on 21/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ROOM_HPP
#define BINDINGOFJEANMICHEL_ROOM_HPP


#include <SFML/System.hpp>
#include "../GraphicEngine/Sprite.hpp"
#include "../PhysicEngine/PhysicObjects.hpp"
#include "NeighbourPosition.hpp"

class Room
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Room              ();
    explicit            Room              (unsigned width, unsigned height);
    virtual             ~Room             ();
    void                display           ();
    void                hide              ();
    void                load              ();
    unsigned            getWidth          ();
    unsigned            getHeight         ();
    void                addSprite         (Sprite* sprite);
    void                addPhysicObjects  (PhysicObjects* object);
    void                addObstacle       (sf::Vector2f position);
    bool                addNeighbour      (NeighBourPosition pos,Room* room);

    static const unsigned standardWidth = 10;
    static const unsigned standardHeight = 6;

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:
    Room              *m_leftRoom,*m_rightRoom,*m_topRoom,*m_bottomRoom;

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    sf::Vector2u                m_dimension;
    std::vector<Sprite*>        m_apsprites;
    std::vector<PhysicObjects*> m_apphysicObjects;
};

#endif //BINDINGOFJEANMICHEL_ROOM_HPP
