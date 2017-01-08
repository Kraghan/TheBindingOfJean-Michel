//
// Created by Kraghan on 21/12/2016.
//

#include "../../Header/Level/Level.hpp"

/* Explicit */ Level::Level()
{

}

/* Virtual */ Level::~Level()
{

}

Room *Level::getFirstRoom()
{
    return &m_aprooms[0];
}

void Level::addRoom(Room room)
{
    room.load();
    room.hide();
    m_aprooms.push_back(room);
}
