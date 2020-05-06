#ifndef Student_hpp
#define Student_hpp

#include <string>
#include "Item.hpp"

using namespace std;

class LinkedListOfStudents;
class Room;
class LinkedListOfItems;

class Student
{
    private:
        string name;
        Room* currentRoom;
        LinkedListOfItems* inventory;


    public:
        Student(string name);
        void setCurrentRoom(Room* currentRoom);
        Room* getCurrentRoom();
        string getName();
        void displayItems();
        void addItem(Item* i);
        int playerItemCount();
        Item* removeItem(string name);
};

#endif