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
    Door* hall175ToHall15 = new Door(hall175, hall15);
    Door* hall15ToHall175 = new Door(hall15, hall175);
    Door* hall15ToHall2 = new Door(hall15, hall2);
    Door* hall2ToHall15 = new Door(hall2, hall15);
    Door* hall2ToRoom18 = new Door(hall2, room118);
    Door* room118tohall2 = new Door(room118, hall2);
    Door* room118ToMac2 = new Door(room118, mac2);
    Door* mac2toroom118 = new Door(mac2, room118);
    Door* mac2toMac1 = new Door(mac2, mac1);
    Door* mac1tomac2 = new Door(mac1, mac2);
    Door* hall2tomac1 = new Door(hall2, mac1);
    Door* mac1tohall2 = new Door(mac1, hall2);
    Door* hall2toAdv1 = new Door(hall2, adv1);
    Door* adv1tohall2 = new Door(adv1, hall2);
    Door* adv1toAdv2 = new Door(adv1, adv2);
    Door* adv2toadv1 = new Door(adv2, adv1);
    Door* hall15toHall1 = new Door(hall15, hall1);
    Door* hall1tohall15 = new Door(hall1, hall15);
    Door* hall1toHall0 = new Door(hall1, hall0);
    Door* hall0tohall1 = new Door(hall0, hall1);
    Door* hall0tolobby = new Door(hall0, lobby);
    Door* lobbytohall0 = new Door(lobby, hall0);
    Door* hall0toroom120 = new Door(hall0, room120);
    Door* room120tohall0 = new Door(room120, hall0);
    Door* lobbytoesport = new Door(lobby, esport);
    Door* esporttolobby = new Door(esport, lobby);
    Door* lobbytooffice = new Door(lobby, office);
    Door* officetolobby = new Door(office, lobby);
    Door* lobbytoserver = new Door(lobby, server);
    Door* servertolobby = new Door(server, lobby);


    //Set Room doors
    hall175->setDoor(hall175ToHall15, "West");
    hall15->setDoor(hall15ToHall175, "East");
    hall15->setDoor(hall15ToHall2, "North");
    hall2->setDoor(hall2ToHall15, "South");
    hall2->setDoor(hall2tomac1, "North");
    mac1->setDoor(mac1tohall2, "South");
    hall2->setDoor(hall2toAdv1, "East");
    adv1->setDoor(adv1tohall2, "West");
    hall2->setDoor(hall2ToRoom18, "West");
    room118->setDoor(room118tohall2, "East");
    room118->setDoor(room118ToMac2, "North");
    mac2->setDoor(mac2toroom118, "South");
    mac2->setDoor(mac2toMac1, "East");
    mac1->setDoor(mac1tomac2, "West");
    adv1->setDoor(adv1toAdv2, "North");
    adv2->setDoor(adv2toadv1, "South");
    hall15->setDoor(hall15toHall1, "South");
    hall1->setDoor(hall1tohall15, "North");
    hall1->setDoor(hall1toHall0, "South");
    hall0->setDoor(hall0tohall1, "North");
    hall0->setDoor(hall0tolobby, "West");
    lobby->setDoor(lobbytohall0, "East");
    hall0->setDoor(hall0toroom120, "South");
    room120->setDoor(room120tohall0, "North");
    lobby->setDoor(lobbytoesport, "South");
    esport->setDoor(esporttolobby, "North");
    lobby->setDoor(lobbytoserver, "North");
    server->setDoor(lobbytoserver, "South");
    lobby->setDoor(lobbytooffice, "West");
    office->setDoor(officetolobby, "West");

    Room* startingRoom = hall175;
    array<Room*, 2> ar = {hall175, room120};
    return ar;
}

Game::Game(string name){
    array<Room*, 2> ar = config();
    this->currentRoom = ar[0];
    this->finalRoom = ar[1];
    this->player = new Student(name);
    this->player->setRoom(this->currentRoom);

}

Student* Game::getPlayer(){
    return this->player;
}

Room* Game::getcurrentRoom(){
    return this->currentRoom;
}
Room* Game::getFinalRoom(){
    return this->finalRoom;
}