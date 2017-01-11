//
// Created by Kraghan on 23/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_TRIGGERACTION_HPP
#define BINDINGOFJEANMICHEL_TRIGGERACTION_HPP


#include "../PhysicObjects.hpp"

class TriggerAction
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            TriggerAction              ();
    virtual             ~TriggerAction             ();
    virtual void        onEnter                    (PhysicObjects* objects) = 0;
    virtual void        onExit                     (PhysicObjects* objects) = 0;
    virtual void        onStay                     (PhysicObjects* objects) = 0;

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //BINDINGOFJEANMICHEL_TRIGGERACTION_HPP
