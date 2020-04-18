
#ifndef Student_hpp
#define Student_hpp
#include <string>
#include "Room.hpp"

using namespace std;

class Student{
    private:
        string name;
        Room* currentRoom;

    public:
    Student(string name);
    string getName();
    void setRoom(Room* currentRoom);
    string getCurrentRoomName();
    Room* getRoom();
};
#endif