//
// Created by Kraghan on 10/01/2017.
//

#ifndef BINDINGOFJEANMICHEL_PROJECTILE_HPP
#define BINDINGOFJEANMICHEL_PROJECTILE_HPP


#include "Entity.hpp"
#include "../GraphicEngine/GraphicEngine.hpp"
#include "../PhysicEngine/PhysicEngine.hpp"

class Projectile : public Entity, public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Projectile              ();
    virtual             ~Projectile             ();

    bool                isDead                  ();
    void                init                    (double timeToLive, unsigned damage, sf::Vector2f position,
                                                 sf::Vector2f dimension, sf::Vector2f speed);
    virtual void        update                  (double dt);
    void                free                    ();

    bool                isFree                  ();
    void                setTexture              (sf::Texture* texture);
    void                kill                    ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    double              m_timeToLive;
    unsigned            m_damage;
    double              m_elapsed;
    bool                m_isFree;
};


#endif //BINDINGOFJEANMICHEL_PROJECTILE_HPP
