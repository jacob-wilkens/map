class Door;
#ifndef Room_hpp
#define Room_hpp
#include <string>
#include "Door.hpp"

using namespace std;

class Room{
    private:
        string name;
        Door* northDoor;
        Door* southDoor;
        Door* eastDoor;
        Door* westDoor;
        //inhabitants

    public:
        Room(string name);
        string getName();
        Door* getDoor(string direction);
        void setDoor(Door* theDoor, string direction);
}; 
#endif