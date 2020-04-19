#include <string>
#include "Student.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include "Game.hpp"
#include <iostream>

using namespace std;

int main(){
    Game* theGame = new Game("Jacob");
    Room* finalRoom = theGame->getFinalRoom();
    Student* player = theGame->getPlayer();
    string input;
    cout << finalRoom->getName() << "\n";
    while(input != "1"){
        if(player->getCurrentRoomName() == finalRoom->getName()){
            cout << "You found the end " << "\n";
            break;
        }
        Room* currentRoom = player->getRoom();
        cout << "You are in room " << currentRoom->getName() << "\n" ;
        cout << "Which direction would you like to try " << "\n" ;
        cin >> input;
        if(input == "quit"){
            break;
        } else {
            if(currentRoom->hasDoor(input) == false){
                cout << currentRoom->getName() << " has no door to the " << input << "\n";
            } else {
                currentRoom = currentRoom->getDoor(input)->getRoomTo();
                player->setRoom(currentRoom);
                cout << "Changing to room " << currentRoom->getName() << "\n";
            }
        }
    }
}