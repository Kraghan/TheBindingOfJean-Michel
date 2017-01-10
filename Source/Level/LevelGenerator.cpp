//
// Created by Kraghan on 05/01/2017.
//

#include "../../Header/Level/LevelGenerator.hpp"

/* Explicit */ LevelGenerator::LevelGenerator()
{

}

/* Virtual */ LevelGenerator::~LevelGenerator()
{

}

Level LevelGenerator::generateLevel(unsigned seed)
{
    Level level = Level();
    /*unsigned nbRoom;
    switch (seed)
    {
        case 1 :
            nbRoom = (unsigned) (rand() % 3 + 5);
            break;
        default:
            nbRoom = rand() % (seed+3) + 5;
    }

    Room* bossRoom = RoomStorage::Instance()->getBossRoom(seed);
    std::vector<Room*> rooms;

    rooms.push_back(RoomStorage::Instance()->getFirstRoom());
    for(unsigned i = 0; i < nbRoom - 2; ++i)
    {
        rooms.push_back(RoomStorage::Instance()->getRandomRoom());
    }
    rooms.push_back(RoomStorage::Instance()->getBossRoom(seed));

    for(unsigned i = 1; i < rooms.size();++i)
    {

    }*/
    level.addRoom(*RoomStorage::Instance()->getFirstRoom());
    return level;
}
