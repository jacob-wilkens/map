#include "Room.hpp"


Room::Room(string name){
    this->name = name;
    this->southDoor = 0;
    this->northDoor = 0;
    this->eastDoor = 0;
    this->westDoor = 0;
}

string Room::getName(){
    return this->name;
}

void Room::setDoor(Door* theDoor, string direction){
    if(direction == "North"){
        this->northDoor = theDoor;
    } else if (direction == "South"){
        this->southDoor = theDoor;
    } else if(direction == "East") {
        this->eastDoor = theDoor;
    } else if (direction == "West") {
        this->westDoor = theDoor;
    }
}

Door* Room::getDoor(string direction){
    if(direction == "North"){
        return this->northDoor;
    } else if (direction == "South"){
        return this->southDoor;
    } else if(direction == "East") {
        return this->eastDoor;
    } else if (direction == "West") {
        return this->westDoor;
    }
}