//
// Created by madjo on 09/01/2017.
//

#ifndef BINDINGOFJEANMICHEL_BOSSROOM_HPP
#define BINDINGOFJEANMICHEL_BOSSROOM_HPP


#include "Room.hpp"

class BossRoom : public Room
{
public:
    explicit            BossRoom           (unsigned width, unsigned height,
                                            unsigned levelMin);
    virtual             ~BossRoom          ();

private :
    unsigned m_levelMin;
};


#endif //BINDINGOFJEANMICHEL_BOSSROOM_HPP
