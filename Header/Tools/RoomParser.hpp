//
// Created by Kraghan on 21/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_ROOMPARSER_HPP
#define BINDINGOFJEANMICHEL_ROOMPARSER_HPP


#include <fstream>
#include <sstream>
#include <string>
#include "../../Header/Room/Room.hpp"
#include <iostream>
#include "../../Header/Room/RoomStorage.hpp"

class RoomParser
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            RoomParser              ();
    virtual             ~RoomParser             ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    const std::string   dirPath = "../res/Rooms/";

    static const unsigned elements = 2;

    const std::string   roomFiles [elements] =
    {
            "0.room",
            "1.room"
    };
};


#endif //BINDINGOFJEANMICHEL_ROOMPARSER_HPP
