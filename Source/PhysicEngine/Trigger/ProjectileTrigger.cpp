//
// Created by Kraghan on 11/01/2017.
//

#include <iostream>
#include "../../../Header/PhysicEngine/Trigger/ProjectileTrigger.hpp"

/* Explicit */ ProjectileTrigger::ProjectileTrigger(Projectile* objects)
: TriggerAction()
{
    m_pprojectile = objects;
}

/* Virtual */ ProjectileTrigger::~ProjectileTrigger()
{

}

/* virtual */ void ProjectileTrigger::onEnter(PhysicObjects* objects)
{
    m_pprojectile->kill();
}

/* virtual */ void ProjectileTrigger::onExit(PhysicObjects* objects)
{

}

/* virtual */ void ProjectileTrigger::onStay(PhysicObjects* objects)
{

}

