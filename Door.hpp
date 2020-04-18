class Room;

#ifndef Door_hpp
#define Door_hpp
#include "Room.hpp"

//room to and from could switch so add setters for those fields

class Door{
    private:
        Room* roomTo;
        Room* roomFrom;

    public:
        Door(Room* roomFrom, Room* roomTo);
        Room* getRoomFrom();
        Room* getRoomTo();
};
#endif