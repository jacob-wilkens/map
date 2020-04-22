#include "Room.hpp"
#include <iostream>
using namespace std;

Room::Room(string title)
{
    this->title = title;
    this-> collectionOfDoors[10];
    this->currentNumberOfDoors = 0;
    this->collectionOfStudents = new LinkedListOfStudents();
}
string Room::getRoomName(){
    return this->title;
}
void Room::addDoor(Door* door){
    this->collectionOfDoors[this->currentNumberOfDoors] = door;
    this->currentNumberOfDoors++;
}
void Room::addStudent(Student* s){
    this->collectionOfStudents->addFront(s);
}
DirectionList* Room::displayDoorDirection(){
    DirectionList* myList = new DirectionList();
    for(int i = 0; i < currentNumberOfDoors; i++){
        Door* currentDoor = collectionOfDoors[i];
        if(currentDoor->getRoomA()->getRoomName() == this->title){
            cout << currentDoor->getRoomB()->getRoomName() << " is to the " << currentDoor->getRoomBDirection() << "\n";
            myList->addFront(currentDoor->getRoomBDirection());
        } else {
            cout << currentDoor->getRoomA()->getRoomName() << " is to the " << currentDoor->getRoomADirection() << "\n";
            myList->addFront(currentDoor->getRoomADirection());
        }
    }
    return myList;
}
Room* Room::getNewRoom(string direction){
    for(int i = 0; i < currentNumberOfDoors; i++){
        Door* currentDoor = collectionOfDoors[i];
        if(currentDoor->getRoomA()->getRoomName() == this->title){
            if(currentDoor->getRoomBDirection() == direction){
                return currentDoor->getRoomB();
            }
        } else if(currentDoor->getRoomB()->getRoomName() == this->title){
            if(currentDoor->getRoomADirection() == direction){
                return currentDoor->getRoomA();
        } else {
            continue;
        }
    }
    }
}
void Room::removeStudent(){
    this->collectionOfStudents->removeFront();
}
void Room::display(){
    this->collectionOfStudents->display();
}