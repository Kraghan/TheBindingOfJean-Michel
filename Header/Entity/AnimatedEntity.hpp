//
// Created by Kraghan on 22/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ANIMATEDENTITY_HPP
#define BINDINGOFJEANMICHEL_ANIMATEDENTITY_HPP


#include "Entity.hpp"
#include "../GraphicEngine/Animation.hpp"

class AnimatedEntity : public Entity
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            AnimatedEntity              ();
    virtual             ~AnimatedEntity             ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:
    Animation           m_animation;

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //BINDINGOFJEANMICHEL_ANIMATEDENTITY_HPP
