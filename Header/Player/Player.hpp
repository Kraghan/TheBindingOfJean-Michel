//
// Created by Kraghan on 22/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_PLAYER_HPP
#define BINDINGOFJEANMICHEL_PLAYER_HPP


#include "../Entity/Entity.hpp"
#include "../Entity/AnimatedEntity.hpp"
#include "../../Header/GraphicEngine/GraphicEngine.hpp"
#include <iostream>

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

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //BINDINGOFJEANMICHEL_PLAYER_HPP
