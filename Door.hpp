class Room;
#include "Room.hpp"
#include <string>
#include <iostream>
#ifndef Door_hpp
#define Door_hpp

using namespace std;

class Door
{
    private:
        string directionToRoomA;
        string directionToRoomB;
        Room* roomA;
        Room* roomB;


    public:
        Door(string directionFrom, Room* roomFrom, string directionTo, Room* roomTo);
        Room* getRoomB();
        Room* getRoomA();
        string getRoomBDirection();
        string getRoomADirection();


};
#endif
