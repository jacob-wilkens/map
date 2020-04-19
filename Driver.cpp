#include <string>
#include "Student.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include "Game.hpp"
#include <iostream>

using namespace std;

string doorAtDirections(Room* currentRoom){
    string directions = "";
    if(currentRoom->hasDoor("North")){
        directions += "North ";
    } if(currentRoom->hasDoor("South")){
        directions += "South ";
    } if(currentRoom->hasDoor("East")){
        directions += "East ";
    }
    if(currentRoom->hasDoor("West")){
        directions += "West ";
    }
    return directions;
}

int main(){
    Game* theGame = new Game("Jacob");
    Room* finalRoom = theGame->getFinalRoom();
    Student* player = theGame->getPlayer();
    Room* currentRoom;
    string input;
    while(player->getCurrentRoomName() != finalRoom->getName()){
        currentRoom = player->getRoom();
        if(currentRoom->peopleCount() == 0){
            currentRoom->addToPeople(player);
        } else {
        cout << "You are in room " << currentRoom->getName() << "\n" ;
        cout << "The current room has " << currentRoom->peopleCount() << " people \n";
        string directions = doorAtDirections(currentRoom);
        cout << "There are rooms " << directions << "\n";
        cout << "Which direction would you like to try " << "\n" ;
        cin >> input;
        if(input == "quit"){
            break;
        } else {
            if(currentRoom->hasDoor(input) == false){
                cout << currentRoom->getName() << " has no door to the " << input << "\n";
            } else {
                Student* person = currentRoom->removePeople();
                currentRoom = currentRoom->getDoor(input)->getRoomTo();
                player->setRoom(currentRoom);
                cout << "Changing to room " << currentRoom->getName() << "\n\n";
                }
            }
        }
    }
}