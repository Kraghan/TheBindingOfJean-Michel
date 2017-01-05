//
// Created by Kraghan on 15/12/2016.
//

#include "../../Header/GraphicEngine/RenderBase.hpp"

/* explicit */ RenderBase::RenderBase()
{
    m_ready = false;
    m_visible = true;
    m_available = true;
    m_smoothMotion = false;
}

/* virtual */ RenderBase::~RenderBase()
{
    // None
}

void RenderBase::update()
{
    // A drawable is ready to be displayed if :
    // He is visible
    // He is not available in the engine (so in use in the game)
    m_ready = !(!m_visible || m_available);
}