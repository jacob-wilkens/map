class Door;
class Student;
class Queue;
#ifndef Room_hpp
#define Room_hpp
#include <string>
#include "Door.hpp"
#include "Student.hpp"
#include "Queue.hpp"


using namespace std;

class Room{
    private:
        string name;
        Door* northDoor;
        Door* southDoor;
        Door* eastDoor;
        Door* westDoor;
        Queue* people;
        

    public:
        Room(string name);
        string getName();
        Door* getDoor(string direction);
        void setDoor(Door* theDoor, string direction);
        bool hasDoor(string direction);
        void addToPeople(Student* person);
        Student* removePeople();
        int peopleCount();
}; 
#endif