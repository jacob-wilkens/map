#include "Door.hpp"



Door::Door(Room* roomTo, Room* roomFrom){
    this->roomFrom = roomFrom;
    this->roomTo = roomTo;
}

Room* Door::getRoomFrom(){
    return this->roomFrom;
}


Room* Door::getRoomTo(){
    return this->roomTo;
}
