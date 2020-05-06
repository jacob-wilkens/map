#include "Student.hpp"
#include "LinkedListOfItems.hpp"
#include "iostream"
using namespace std;

Student::Student(string name)
{
    this->name = name;
    this->currentRoom = 0;
    this->inventory = new LinkedListOfItems();
}
void Student::setCurrentRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}
Room* Student::getCurrentRoom(){
    return this->currentRoom;
}
string Student::getName(){
    return this->name;
}
void Student::displayItems(){
    if(this->inventory->getCount() == 0){
        cout << "There are no items in the inventory \n";
    } else {
        this->inventory->display();
    }
}
void Student::addItem(Item* i){
    this->inventory->addFront(i);
}
int Student::playerItemCount(){
    return this->inventory->getCount();
}
Item* Student::removeItem(string name){
        if(this->inventory->getCount() == 0){
        cout << "No items to remove \n";
        return 0;
    } else {
        Item* itemToRemove; 
        int index = this->inventory->findIndexByName(name);
        if(index == -1){
            cout << "Item does not exit\n";
            Item* tempItem = new Item("");
            return tempItem;
        } else {
        itemToRemove = this->inventory->removeAtIndex(index);
        return itemToRemove;
        }
    }
}