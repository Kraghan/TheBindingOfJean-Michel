//
// Created by Kraghan on 23/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_PHYSICENGINE_HPP
#define BINDINGOFJEANMICHEL_PHYSICENGINE_HPP


#include "../Tools/Updatable.hpp"
#include "../Tools/Singleton.hpp"
#include "PhysicObjects.hpp"

class PhysicEngine : public Updatable, public Singleton < PhysicEngine >
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            PhysicEngine              ();
    virtual             ~PhysicEngine             ();
    virtual void        update                    (double dt);
    void                init                      (unsigned physicObjectCount);
    PhysicObjects*      getPhysicObject           ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    PhysicObjects*      m_aphysicObjects;
    unsigned            m_physicObjectsCount;
    void                processCollision          (PhysicObjects* object);
};

#endif //BINDINGOFJEANMICHEL_PHYSICENGINE_HPP
