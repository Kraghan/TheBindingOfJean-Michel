//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_MENUSTATE_HPP
#define BINDINGOFJEANMICHEL_MENUSTATE_HPP

#include "State.hpp"
#include "../Tools/Singleton.hpp"
#include "../../Header/GraphicEngine/GraphicEngine.hpp"

class MenuState : public State, public Singleton <MenuState>
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            MenuState              ();
    virtual             ~MenuState             ();
    virtual bool        onEnter                ();
    virtual bool        onExit                 ();
    virtual void        onPollEvent            (sf::Event e);
    void                init                   ();
    virtual void        update                 (double dt) ;

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //BINDINGOFJEANMICHEL_MENUSTATE_HPP
