//
// Created by Kraghan on 21/12/2016.
//

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

Room *RoomStorage::getBossRoom()
{
    return nullptr;
}

Room *RoomStorage::getRoomBySize(unsigned width, unsigned height)
{
    return nullptr;
}

Room* RoomStorage::addRoom(unsigned width, unsigned height, bool isBossRoom)
{
    m_storage.push_back(Room(width,height,isBossRoom));
    return &m_storage[m_storage.size()-1];
}

