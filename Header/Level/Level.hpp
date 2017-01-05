//
// Created by Kraghan on 21/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_LEVEL_HPP
#define BINDINGOFJEANMICHEL_LEVEL_HPP


#include <vector>
#include "../Room/Room.hpp"
#include "../../Header/Room/RoomStorage.hpp"
#include "../../Header/GraphicEngine/GraphicEngine.hpp"

class Level
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Level              ();
    virtual             ~Level             ();
    Room*               getFirstRoom       ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    std::vector<Room*> m_aprooms;
};


#endif //BINDINGOFJEANMICHEL_LEVEL_HPP
