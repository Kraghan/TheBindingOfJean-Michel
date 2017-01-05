//
// Created by Kraghan on 21/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ROOM_HPP
#define BINDINGOFJEANMICHEL_ROOM_HPP


#include <SFML/System.hpp>
#include "../GraphicEngine/Sprite.hpp"
#include "../PhysicEngine/PhysicObjects.hpp"

class Room
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Room              ();
    explicit            Room              (unsigned width, unsigned height, bool isBossRoom);
    virtual             ~Room             ();
    void                display           ();
    void                hide              ();
    unsigned            getWidth          ();
    unsigned            getHeight         ();
    void                addSprite         (Sprite* sprite);
    void                addPhysicObjects  (PhysicObjects* object);
    void                addObstacle       (sf::Vector2f position);

    static const unsigned standardWidth = 10;
    static const unsigned standardHeight = 6;

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    sf::Vector2u                m_dimension;
    bool                        m_isBossRoom;
    std::vector<Sprite*>        m_apsprites;
    std::vector<PhysicObjects*> m_apphysicObjects;
};

#endif //BINDINGOFJEANMICHEL_ROOM_HPP
