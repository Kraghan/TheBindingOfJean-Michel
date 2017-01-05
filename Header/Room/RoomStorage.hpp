//
// Created by Kraghan on 21/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ROOMSTORAGE_HPP
#define BINDINGOFJEANMICHEL_ROOMSTORAGE_HPP


#include <vector>
#include "Room.hpp"
#include "../Tools/Singleton.hpp"
#include "../PhysicEngine/PhysicEngine.hpp"

class RoomStorage : public Singleton < RoomStorage >
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            RoomStorage              ();
    virtual             ~RoomStorage             ();
    Room*               getRandomRoom            ();
    Room*               getBossRoom              ();
    Room*               getRoomBySize            (unsigned width,unsigned height);
    Room*               addRoom                  (unsigned width, unsigned height, bool isBossRoom);
    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    std::vector<Room> m_storage;
};


#endif //BINDINGOFJEANMICHEL_ROOMSTORAGE_HPP
