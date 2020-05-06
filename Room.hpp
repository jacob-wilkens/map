#ifndef Room_hpp
#define Room_hpp
class Door; // allows us to reference door when door refereneces Room.
class Student;
class LinkedListOfStudents;
#include <string>
#include "LinkedListOfStudents.hpp"
#include "Door.hpp"
#include "Student.hpp"
#include <iostream>
#include "DirectionList.hpp"
#include "LinkedListOfItems.hpp"
#include "Item.hpp"
using namespace std;

class Room
{
    private:
        string title;
        Door* collectionOfDoors[10];
        int currentNumberOfDoors;
        LinkedListOfStudents* collectionOfStudents;
        int itemCount;
        int maxItemCount;
        LinkedListOfItems* items;

        
    
    public:
        Room(string title);
        string getRoomName();
        void addDoor(Door* door);
        void addStudent(Student* s);
        DirectionList* displayDoorDirection();
        Room* getNewRoom(string direction);
        void removeStudent();
        void display();
        void addItem(Item* item);
        void displayItems();
        Item* removeItem(string name);
        int getItemCount();


};
#endif