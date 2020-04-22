#include "Door.hpp"

Door::Door(string directionFrom, Room* roomFrom, string directionTo, Room* roomTo)
{
    this->directionToRoomA = directionFrom;
    this->directionToRoomB = directionTo;
    this->roomA = roomFrom;
    this->roomB = roomTo;
}
Room* Door::getRoomB(){
    return this->roomB;
}
Room* Door::getRoomA(){
    return this->roomA;
}      
string Door::getRoomADirection(){
    return this->directionToRoomA;
}      
string Door::getRoomBDirection(){
    return this->directionToRoomB;
}  