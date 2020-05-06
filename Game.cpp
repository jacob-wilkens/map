#include "Game.hpp"

array<Room*,2> Game::config(){

    //Items
    Item* item1 = new Item("Pencil");
    Item* item2 = new Item("Pen");
    Item* item3 = new Item("Marker");
    Item* item4 = new Item("Eraser");
    Item* item5 = new Item("Bag");
    Item* item6 = new Item("Notebook");
    Item* item7 = new Item("Book");
    Item* item8 = new Item("Folder");
    Item* item9 = new Item("Box");
    Item* item10 = new Item("Mat");

    //Rooms
    Room* hall175 = new Room("Hallway 1.75");
    hall175->addItem(item1);
    Room* hall15 = new Room("Hallway 1.5");
    hall15->addItem(item2);
    Room* hall2 = new Room("Hallway 2");
    hall2->addItem(item3);
    Room* hall1 = new Room("Hallway 1");
    hall1->addItem(item4);
    Room* hall0 = new Room("Hallway 0");
    hall0->addItem(item5);
    Room* mac1 = new Room("Mac Lab 1");
    mac1->addItem(item6);
    Room* mac2 = new Room("Mac Lab 2");
    mac2->addItem(item7);
    Room* adv1 = new Room("Adv. Lab 1");
    adv1->addItem(item8);
    Room* adv2 = new Room("Adv. Lab 2");
    adv2->addItem(item9);
    Room* room118 = new Room("118");
    room118->addItem(item10);
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
        this->currentRoom->addStudent(this->player);
        cout << "The current room is " << this->currentRoom->getRoomName() << "\n";
        cout << "The following students in the room are: ";
        this->currentRoom->display();
        cout << "\n";
        if(this->player->playerItemCount() > 0){
            string remove;
            cout << "Would you like to remove and item: ";
            cin >> remove;
            if(remove == "Yes" || remove == "Y"){
                string itemName;
                cout << "Enter the name of the item: ";
                cin >> itemName;
                Item* removedItem = this->player->removeItem(itemName);
                if(removedItem->getName() != ""){
                    cout << "Item removed is: " << removedItem->getName();
                    cout << "\n";
                    this->currentRoom->addItem(removedItem);
                }
            }

        }
        if(this->currentRoom->getItemCount() >= 0){
            this->currentRoom->displayItems();
            cout << "\n";
            string answer;
            cout << "Would you like to pickup an item: ";
            cin >> answer;
            if(answer == "Y" || answer == "Yes"){
                string itemName;
                cout << "Enter the name of the item: ";
                cin >> itemName;
                Item* removedItem = this->currentRoom->removeItem(itemName);
                if(removedItem->getName() != ""){
                    cout << "Item removed is: " << removedItem->getName();
                    this->player->addItem(removedItem);
                }
            }
        }
        if(this->player->playerItemCount() > 0){
            cout << "\n" << "Would you like to view the inventory: ";
            string inventoryInput;
            cin >> inventoryInput;
            if(inventoryInput == "Y" || inventoryInput == "Yes"){
                this->player->displayItems();
                cout << "\n";
        }
        }
        DirectionList* directions = this->currentRoom->displayDoorDirection();
        cout << "Which direction would you like to go ";
        string input;
        cin >> input;
        while(inputCheck(input, directions) == false){
            cout << "Which direction would you like to go ";
            cin >> input;
        }
        cout << "\n";
        currentRoom->removeStudent();
        this->currentRoom = this->currentRoom->getNewRoom(input);
        this->player->setCurrentRoom(this->currentRoom);
    }
}