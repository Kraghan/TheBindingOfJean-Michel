//
// Created by Kraghan on 22/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ENTITY_HPP
#define BINDINGOFJEANMICHEL_ENTITY_HPP


#include <SFML/System/Vector2.hpp>
#include "../GraphicEngine/Sprite.hpp"
#include "../PhysicEngine/PhysicObjects.hpp"

class Entity
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Entity              ();
    virtual             ~Entity             ();
    void                setLife             (int life);
    PhysicObjects*      getPhysicObject     ();
    void                init                (int life, sf::Vector2f position, sf::Vector2f dimension, float maxSpeed, float acceleration);
    void                activePhysic        ();
    void                deactivePhysic      ();
    void                hit                 (unsigned damage);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    Sprite*             m_sprite;
    PhysicObjects*      m_physicObject;

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    int                 m_hitPoint;
};


#endif //BINDINGOFJEANMICHEL_ENTITY_HPP
