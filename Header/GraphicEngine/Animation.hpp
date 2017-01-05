//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ANIMATION_HPP
#define BINDINGOFJEANMICHEL_ANIMATION_HPP


#include <string>
#include "../Tools/Updatable.hpp"
#include "AnimationState.hpp"

class Animation : public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Animation              ();
    virtual             ~Animation             ();
    virtual void        update                 (double dt);
    void                addState               (std::string const&& key, AnimationState const&& state);
    AnimationState *    getState               (std::string const& key);
    void                setState               (std::string const& key);
    void                pause                  ();
    void                start                  ();
    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    bool m_play;
    AnimationState * m_currentState;
    std::map < std::string, AnimationState > m_stateList;
};


#endif //BINDINGOFJEANMICHEL_ANIMATION_HPP
