#include "Room.hpp"
#include <iostream>
using namespace std;

Room::Room(string title)
{
    this->title = title;
    this-> collectionOfDoors[10];
    this->currentNumberOfDoors = 0;
    this->collectionOfStudents = new LinkedListOfStudents();
    this->itemCount = 0;
    this->maxItemCount = 5;
    this->items = new LinkedListOfItems();
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
void Room::displayItems(){
    if(this->itemCount == 0){
        cout << "There are no items in " << this->getRoomName();
    } else {
        cout << "The items in the room are ";
        this->items->display();
    }
}
void Room::addItem(Item* i){
    this->items->addFront(i);
    this->itemCount++;
}
Item* Room::removeItem(string name){
    if(this->itemCount == 0){
        cout << "No items to remove \n";
        Item* tempItem = new Item("");
        return 0;
    } else {
        Item* itemToRemove; 
        int index = this->items->findIndexByName(name);
        if(index == -1){
            cout << "Item does not exit\n";
            Item* tempItem = new Item("");
            return tempItem;
        } else {
        itemToRemove = this->items->removeAtIndex(index);
        this->itemCount--;
        return itemToRemove;
        }
    }
}
int Room::getItemCount(){
    return this->itemCount;
}