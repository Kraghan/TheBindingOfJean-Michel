//
// Created by Kraghan on 22/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_PLAYER_HPP
#define BINDINGOFJEANMICHEL_PLAYER_HPP


#include "../Entity/Entity.hpp"
#include "../Entity/AnimatedEntity.hpp"
#include "../../Header/GraphicEngine/GraphicEngine.hpp"
#include <iostream>
#include "../../Header/Tools/Position.hpp"
#include "../Entity/Projectile.hpp"

class Player : public AnimatedEntity, public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Player              ();
    virtual             ~Player             ();
    virtual void        update              (double dt);
    void                init                ();
    void                startAnimation      (std::string name);
    void                shoot               (Position position);
    void                setHeadOrientation  (Position position);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    Sprite*                     m_headSprite;
    Animation                   m_headAnimation;
    std::vector<Projectile>     m_projectiles;
    double                      m_timeSinceLastShoot;
    double                      m_timeBetweenShoot;
    const unsigned              NB_PROJECTILES = 25;
};


#endif //BINDINGOFJEANMICHEL_PLAYER_HPP
