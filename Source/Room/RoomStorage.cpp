//
// Created by Kraghan on 21/12/2016.
//

#include <iostream>
#include "../../Header/Room/RoomStorage.hpp"

/* Explicit */ RoomStorage::RoomStorage()
{

}

/* Virtual */ RoomStorage::~RoomStorage()
{

}

Room *RoomStorage::getRandomRoom()
{
    return &m_storage[rand() % m_storage.size()];
}

Room *RoomStorage::getBossRoom(unsigned seed)
{
    std::map<unsigned int, std::vector<BossRoom>>::iterator it =
            m_bossStorage.find(seed);
    if(it == m_bossStorage.end())
        return nullptr;

    std::vector<BossRoom> rooms = it->second;
    return &rooms[rand()%rooms.size()];
}

Room *RoomStorage::getRoomBySize(unsigned width, unsigned height)
{
    return nullptr;
}

Room* RoomStorage::addRoom(unsigned width, unsigned height, unsigned levelBoss)
{
    Room* r;
    if(levelBoss == 0)
    {
        m_storage.push_back(Room(width, height));
        r = &m_storage[m_storage.size()-1];
    }
    else
    {
        std::map<unsigned int, std::vector<BossRoom>>::iterator it =
                m_bossStorage.find(levelBoss);
        if(it != m_bossStorage.end())
        {
            it->second.push_back(BossRoom(width,height,levelBoss));
            r = &it->second[m_storage.size() - 1];
        }
        else
        {
            std::vector<BossRoom> v;
            v.push_back(BossRoom(width,height,levelBoss));
            r = &v[0];
            m_bossStorage.emplace(levelBoss,v);
        }
    }
    return r;
}

Room *RoomStorage::getFirstRoom()
{
    return &m_storage[0];
}

