//
// Created by Kraghan on 11/01/2017.
//

#ifndef BINDINGOFJEANMICHEL_PROJECTILETRIGGER_HPP
#define BINDINGOFJEANMICHEL_PROJECTILETRIGGER_HPP


#include "TriggerAction.hpp"
#include "../../Entity/Projectile.hpp"
#include "../../Player/Player.hpp"

class ProjectileTrigger : public TriggerAction
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            ProjectileTrigger               (Projectile* objects);
    virtual             ~ProjectileTrigger              ();
    virtual void        onEnter                         (PhysicObjects* objects);
    virtual void        onExit                          (PhysicObjects* objects);
    virtual void        onStay                          (PhysicObjects* objects);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //-----------------------------------------------------------------------------------------------------------------
private:
    Projectile*         m_pprojectile;
};


#endif //BINDINGOFJEANMICHEL_PROJECTILETRIGGER_HPP
