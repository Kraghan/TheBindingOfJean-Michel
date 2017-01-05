//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_DRAWABLEMANAGER_HPP
#define BINDINGOFJEANMICHEL_DRAWABLEMANAGER_HPP

template <typename T>
class DrawableManager
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            DrawableManager              ();
    virtual             ~DrawableManager             ();
    void                init                         (unsigned int size);
    T *                 getFreeDrawable              ();
    const T *           getDrawableList              () const;
    unsigned int        getDrawableCount             () const;

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    unsigned int m_size;
    T * m_drawableList;
};

#include "DrawableManager.inl"

#endif //BINDINGOFJEANMICHEL_DRAWABLEMANAGER_HPP
