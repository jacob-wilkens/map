#include "Door.hpp"



Door::Door(Room* roomFrom, Room* roomTo){
    this->roomFrom = roomFrom;
    this->roomTo = roomTo;
}

Room* Door::getRoomFrom(){
    return this->roomFrom;
}


Room* Door::getRoomTo(){
    return this->roomTo;
}
