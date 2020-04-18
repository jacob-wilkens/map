#include "Student.hpp"

Student::Student(string name){
    this->name = name;
    this->currentRoom = 0;
}

string Student::getName(){
    return this->name;
}
void Student::setRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}
string Student::getCurrentRoomName(){
    return this->currentRoom->getName();
}
Room* Student::getRoom(){
    return this->currentRoom;
}