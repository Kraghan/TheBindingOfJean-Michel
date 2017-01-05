//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ANIMATIONSTATE_HPP
#define BINDINGOFJEANMICHEL_ANIMATIONSTATE_HPP


#include "../Tools/Updatable.hpp"
#include "Sprite.hpp"

class AnimationState : Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            AnimationState              ();
    virtual             ~AnimationState             ();
    void                init                        (Sprite * pSrite, bool repeat,
                                                      sf::Vector2i pos, sf::Vector2i size,
                                                      int offset, char step, double delay);
    virtual void        update                      (double dt);
    void                setRepeat                   (bool repeat);
    void                onEnter                     ();


    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    Sprite * m_sprite;

    bool m_repeat;
    sf::Vector2i m_size;
    sf::Vector2i m_position;

    char m_step;
    char m_currentStep;

    int m_offset;
    double m_delay;
    double m_elapsed;
};


#endif //BINDINGOFJEANMICHEL_ANIMATIONSTATE_HPP
