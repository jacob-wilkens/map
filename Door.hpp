class Room;

#ifndef Door_hpp
#define Door_hpp
#include "Room.hpp"

class Door{
    private:
        Room* roomTo;
        Room* roomFrom;

    public:
        Door(Room* roomTo, Room* roomFrom);
        Room* getRoomFrom();
        Room* getRoomTo();
};
#endif