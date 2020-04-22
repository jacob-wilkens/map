#ifndef Student_hpp
#define Student_hpp

#include <string>

using namespace std;

class LinkedListOfStudents;
class Room;

class Student
{
    private:
        string name;
        Room* currentRoom;

    public:
        Student(string name);
        void setCurrentRoom(Room* currentRoom);
        Room* getCurrentRoom();
        string getName();
};

#endif