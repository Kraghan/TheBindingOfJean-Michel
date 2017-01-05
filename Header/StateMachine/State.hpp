//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_STATE_HPP
#define BINDINGOFJEANMICHEL_STATE_HPP


#include <SFML/Window/Event.hpp>
#include "../Tools/Updatable.hpp"

class State : public Updatable
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            State              ();

    virtual             ~State             ();

    virtual bool        onEnter            () = 0;

    virtual bool        onExit             () = 0;

    virtual void        onPollEvent        (sf::Event e) = 0;

    virtual void        update             (double dt) = 0;

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //BINDINGOFJEANMICHEL_STATE_HPP
