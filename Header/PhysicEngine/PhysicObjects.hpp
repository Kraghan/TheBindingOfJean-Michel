//
// Created by Kraghan on 23/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_PHYSICOBJECTS_HPP
#define BINDINGOFJEANMICHEL_PHYSICOBJECTS_HPP


#include <SFML/System/Vector2.hpp>
#include <vector>
#include "../Tools/Updatable.hpp"

class TriggerAction;
class Entity;

class PhysicObjects : public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            PhysicObjects               ();
    virtual             ~PhysicObjects              ();
    void                initAsCollider              (sf::Vector2f position, sf::Vector2f dimension);
    void                initAsRigidBody             (sf::Vector2f position, float maxSpeed, float acceleration);
    void                initAsMovingCollider        (sf::Vector2f position, sf::Vector2f dimension, float maxSpeed, float acceleration);
    void                initAsTrigger               (sf::Vector2f position,sf::Vector2f dimension, TriggerAction* action);
    void                initAsMovingTrigger         (sf::Vector2f position, sf::Vector2f dimension, float maxSpeed,
                                                     float acceleration, TriggerAction* action);

    void                startMoveLeft               ();
    void                startMoveRight              ();
    void                startMoveUp                 ();
    void                startMoveDown               ();
    void                stopMoveLeft                ();
    void                stopMoveRight               ();
    void                stopMoveDown                ();
    void                stopMoveUp                  ();
    void                setActive                   ();
    void                setInactive                 ();
    bool                isMovingLeft                ();
    bool                isMovingRight               ();
    bool                isMovingDown                ();
    bool                isMovingUp                  ();
    void                blockMovingLeft             (bool value);
    void                blockMovingRight            (bool value);
    void                blockMovingDown             (bool value);
    void                blockMovingUp               (bool value);
    void                killVerticalKinetic         ();
    void                killHorizontalKinetic       ();

    bool                isUsed                      ();
    bool                isReady                     ();
    bool                isActive                    ();
    bool                isRigidBody                 ();
    bool                isCollider                  ();
    bool                isTrigger                   ();
    bool                isInContact                 (PhysicObjects* object);
    void                addContact                  (PhysicObjects* object);
    void                clearContact                ();
    void                bindEntity                  (Entity* entity);
    Entity*             getBindedEntity             ();

    void                update                      (double dt);

    sf::Vector2f        getPosition                 ();
    sf::Vector2f        getDimension                ();

    static void         release                     (PhysicObjects * &object);

    sf::Vector2f        isColliding                 (PhysicObjects* object);

    inline void         impulse                     (float x, float y)
    {
        if(!m_isRigidBody)
            return;
        m_velocity.x += x;
        m_velocity.y += y;
    }

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:
    friend class PhysicEngine;

    inline void         setUsed                     ()
    {
        m_isUsed = true;
    }

    inline void         setFree                     ()
    {
        m_isUsed = false;
        m_isReady = false;
        m_active = false;
    }

    inline void         move                        (float x, float y)
    {
        if(!m_isRigidBody)
            return;
        m_position.x += x;
        m_position.y += y;
    }

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    bool                        m_isUsed;
    bool                        m_isReady;
    bool                        m_isCollider;
    bool                        m_isRigidBody;
    TriggerAction*              m_triggerAction;
    sf::Vector2f                m_position;
    sf::Vector2f                m_dimension;
    sf::Vector2f                m_velocity;
    float                       m_maxSpeed;
    float                       m_acceleration;
    bool                        m_isMovingLeft, m_isMovingRight, m_isMovingUp, m_isMovingDown;
    bool                        m_blockMovingLeft, m_blockMovingRight, m_blockMovingUp, m_blockMovingDown;
    bool                        m_active;
    std::vector<PhysicObjects*> m_colliderContact;
    Entity*                     m_pentity;

    const float                 coeffFriction = 5.0f;
};


#endif //BINDINGOFJEANMICHEL_PHYSICOBJECTS_HPP
