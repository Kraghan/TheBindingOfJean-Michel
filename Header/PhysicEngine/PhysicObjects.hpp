//
// Created by Kraghan on 23/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_PHYSICOBJECTS_HPP
#define BINDINGOFJEANMICHEL_PHYSICOBJECTS_HPP


#include <SFML/System/Vector2.hpp>
#include "Trigger/TriggerAction.hpp"
#include "../Tools/Updatable.hpp"

class PhysicObjects : public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            PhysicObjects              ();
    virtual             ~PhysicObjects             ();
    void                initAsCollider             (sf::Vector2f position, sf::Vector2f dimension);
    void                initAsRigidBody            (sf::Vector2f position, float maxSpeed, float acceleration);
    void                initAsMovingCollider       (sf::Vector2f position, sf::Vector2f dimension, float maxSpeed, float acceleration);
    void                initAsTrigger              (sf::Vector2f position, sf::Vector2f dimension, TriggerAction*
    action);

    void                startMoveLeft       ();
    void                startMoveRight      ();
    void                startMoveUp         ();
    void                startMoveDown       ();
    void                stopMoveLeft        ();
    void                stopMoveRight       ();
    void                stopMoveDown        ();
    void                stopMoveUp          ();
    void                setActive           ();
    void                setInactive         ();
    bool                isMovingLeft        ();
    bool                isMovingRight       ();
    bool                isMovingDown        ();
    bool                isMovingUp          ();

    bool                isUsed              ();
    bool                isReady             ();
    bool                isActive            ();
    bool                isRigidBody         ();
    bool                isCollider          ();
    bool                isTrigger           ();

    void                update              (double dt);

    sf::Vector2f        getPosition         ();
    sf::Vector2f        getDimension        ();

    static void         release             (PhysicObjects * &object);

    sf::Vector2f        isColliding         (PhysicObjects* object);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:
    friend class PhysicEngine;

    inline void         setUsed             ()
    {
        m_isUsed = true;
    }

    inline void         setFree             ()
    {
        m_isUsed = false;
        m_isReady = false;
        m_active = false;
    }

    inline void         move                (float x, float y)
    {
        m_position.x += x;
        m_position.y += y;
    }

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    bool                m_isUsed;
    bool                m_isReady;
    bool                m_isCollider;
    bool                m_isRigidBody;
    TriggerAction*      m_triggerAction;
    sf::Vector2f        m_position;
    sf::Vector2f        m_dimension;
    sf::Vector2f        m_velocity;
    float               m_maxSpeed;
    float               m_acceleration;
    bool                m_isMovingLeft, m_isMovingRight, m_isMovingUp, m_isMovingDown;
    bool                m_active;

    const float         coeffFriction = 5.0f;
};


#endif //BINDINGOFJEANMICHEL_PHYSICOBJECTS_HPP
