#include "Game.hpp"

array<Room*,2> Game::config(){

    //Rooms
    Room* hall175 = new Room("Hallway 1.75");
    Room* hall15 = new Room("Hallway 1.5");
    Room* hall2 = new Room("Hallway 2");
    Room* hall1 = new Room("Hallway 1");
    Room* hall0 = new Room("Hallway 0");
    Room* mac1 = new Room("Mac Lab 1");
    Room* mac2 = new Room("Mac Lab 2");
    Room* adv1 = new Room("Adv. Lab 1");
    Room* adv2 = new Room("Adv. Lab 2");
    Room* room118 = new Room("118");
    Room* server = new Room("Server Room");
    Room* office = new Room("Locklair's Office");
    Room* lobby = new Room("Lobby");
    Room* esport = new Room("Esports");
    Room* room120 = new Room("120");

    //Doors
    Door* hall15andhall175 = new Door("East", hall175, "West", hall15);
    Door* hall15andhall2 = new Door("South", hall15,"North", hall2);
    Door* hall2androom118 = new Door("East", hall2,"West", room118);
    Door* room118andmac2 = new Door("South", room118,"North", mac2);
    Door* mac2andmac1 = new Door("West", mac2,"East", mac1);
    Door* mac1andhall2 = new Door("South", hall2,"North", mac1);
    Door* hall2andadv1 = new Door("West", hall2,"East", adv1);
    Door* adv1andadv2 = new Door("South", adv1,"North", adv2);
    Door* hall15andhall1 = new Door("North", hall15,"South", hall1);
    Door* hall1andhall0 = new Door("North", hall1,"South", hall0);
    Door* hall0androom120 = new Door("North", hall0,"South", room120);
    Door* hall0andlobby = new Door("East", hall0,"West", lobby);
    Door* lobbyandserver = new Door("South", lobby,"North", server);
    Door* lobbyandoffice = new Door("West", office,"East", lobby);
    Door* lobbyandesport = new Door("North", lobby,"South", esport);




    //Set Room doors
    hall175->addDoor(hall15andhall175);
    hall15->addDoor(hall15andhall175);
    hall15->addDoor(hall15andhall1);
    hall15->addDoor(hall15andhall2);
    hall2->addDoor(hall2andadv1);
    hall2->addDoor(hall2androom118);
    hall2->addDoor(mac1andhall2);
    hall2->addDoor(hall15andhall2);
    mac1->addDoor(mac1andhall2);
    mac1->addDoor(mac2andmac1);
    adv1->addDoor(adv1andadv2);
    adv1->addDoor(hall2andadv1);
    adv2->addDoor(adv1andadv2);
    room118->addDoor(room118andmac2);
    room118->addDoor(hall2androom118);
    mac2->addDoor(room118andmac2);
    mac2->addDoor(mac2andmac1);
    hall1->addDoor(hall15andhall1);
    hall1->addDoor(hall1andhall0);
    hall0->addDoor(hall0andlobby);
    hall0->addDoor(hall1andhall0);
    hall0->addDoor(hall0androom120);
    room120->addDoor(hall0androom120);
    lobby->addDoor(hall0andlobby);
    lobby->addDoor(lobbyandesport);
    lobby->addDoor(lobbyandoffice);
    lobby->addDoor(lobbyandserver);
    esport->addDoor(lobbyandesport);
    server->addDoor(lobbyandserver);
    office->addDoor(lobbyandoffice);


    Room* startingRoom = hall175;
    array<Room*, 2> ar = {hall175, room120};
    return ar;
}

bool Game::inputCheck(string input, DirectionList* directions){
    bool isCorrect = false;
   for(int i = 0; i < directions->getCount(); i++){
       if(input == directions->getIndex(i)) {
           isCorrect = true;
           return isCorrect;
       }
   } 
   cout << "Invalid Direction\n";
   return isCorrect;
}

Game::Game(string name){
    array<Room*, 2> ar = config();
    this->currentRoom = ar[0];
    this->finalRoom = ar[1];
    this->player = new Student(name);
    this->player->setCurrentRoom(this->currentRoom);

}

void Game::begin(){
   
    while(this->finalRoom->getRoomName() != this->player->getCurrentRoom()->getRoomName()){
        Room* currentRoom = this->player->getCurrentRoom();
        currentRoom->addStudent(this->player);
        cout << "The current room is " << currentRoom->getRoomName() << "\n";
        cout << "The following students in the room are: ";
        currentRoom->display();
        cout << "\n";
        DirectionList* directions = currentRoom->displayDoorDirection();
        cout << "Which direction would you like to go ";
        string input;
        cin >> input;
        while(inputCheck(input, directions) == false){
            cout << "Which direction would you like to go ";
            cin >> input;
        }
        cout << "\n";
        currentRoom->removeStudent();
        currentRoom = currentRoom->getNewRoom(input);
        this->player->setCurrentRoom(currentRoom);
    }
}