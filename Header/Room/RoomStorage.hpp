//
// Created by Kraghan on 21/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ROOMSTORAGE_HPP
#define BINDINGOFJEANMICHEL_ROOMSTORAGE_HPP


#include <vector>
#include "Room.hpp"
#include "../Tools/Singleton.hpp"
#include "../PhysicEngine/PhysicEngine.hpp"
#include "BossRoom.hpp"

class RoomStorage : public Singleton < RoomStorage >
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            RoomStorage              ();
    virtual             ~RoomStorage             ();
    Room*               getFirstRoom             ();
    Room*               getRandomRoom            ();
    Room*               getBossRoom              (unsigned seed);
    Room*               getRoomBySize            (unsigned width,unsigned height);
    Room*               addRoom                  (unsigned width, unsigned
                                                    height, unsigned bossLevel);
    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    std::vector<Room>                           m_storage;
    std::map<unsigned,std::vector<BossRoom>>    m_bossStorage;
};


#endif //BINDINGOFJEANMICHEL_ROOMSTORAGE_HPP
