//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_RENDERBASE_HPP
#define BINDINGOFJEANMICHEL_RENDERBASE_HPP

class Sprite;

class RenderBase
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            RenderBase              ();
    virtual             ~RenderBase             ();

    inline bool         isReady                 () const
    {
        return m_ready;
    }

    inline bool         isVisible               () const
    {
        return m_visible;
    }

    inline void         setVisible              (const bool visible)
    {
        m_visible = visible;
        update();
    }

    inline void         setSmoothMotion         (bool state)
    {
        m_smoothMotion = state;
    }

    inline bool         getSmoothMotion         ()const
    {
        return m_smoothMotion;
    }

    // Todo : Make it work with new physic engine
    /*inline void bindRigidBody(RigidBody * ref) {
        m_rigidBodyRef = ref;
    }

    inline RigidBody * getRigidBody() const {
        return m_rigidBodyRef;
    }*/

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:
    friend class GraphicEngine;
    template <typename T> friend class DrawableManager;

    inline bool         isAvailable             () const
    {
        return m_available;
    }

    inline void         setAvailable            (const bool available)
    {
        m_available = available;
        update();
    }

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    void                update                  ();

    bool m_ready;
    bool m_visible;
    bool m_available;
    bool m_smoothMotion;

    // Todo : Make it work with new physic engine
    //RigidBody * m_rigidBodyRef;
};


#endif //BINDINGOFJEANMICHEL_RENDERBASE_HPP
