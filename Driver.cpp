#include <string>
#include "Student.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include <iostream>

using namespace std;

Room* config(){
    //Rooms
    Room* firstRoom = new Room("Hallway 1.75");
    Room* secondRoom = new Room("Hallway 1.5");
    Room* thirdRoom = new Room("Hallway 1.75");
    Room* fourthRoom = new Room("Hallway 1.75");
    Room* fifthRoom = new Room("Hallway 1.75");
    Room* sixthRoom = new Room("Hallway 1.75");
    Room* seventhRoom = new Room("Hallway 1.75");
    Room* eighthRoom = new Room("Hallway 1.75");
    Room* ninthRoom = new Room("Hallway 1.75");
    Room* tenthRoom = new Room("Hallway 1.75");
    Room* eleventhRoom = new Room("Hallway 1.75");
    Room* twelvthRoom = new Room("Hallway 1.75");
    Room* thirteenthRoom = new Room("Hallway 1.75");
    Room* fourteenthRoom = new Room("Hallway 1.75");
    Room* fifteenthRoom = new Room("Hallway 1.75");

    //Doors
    Door* firstDoor = new Door(secondRoom, firstRoom);

    //Set Room doors
    firstRoom->setDoor(firstDoor, "West");
    secondRoom->setDoor(firstDoor, "East");

    return firstRoom;
}

int main(){
    Room* startingRoom = config();
    cout << startingRoom->getName();

}