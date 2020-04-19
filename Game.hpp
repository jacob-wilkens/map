#include "Student.hpp"
#include "Door.hpp"
#include "Room.hpp"
#include <string>
#include <array>
using namespace std;

class Game{
    private:
        Student* player;
        Room* currentRoom;
        array<Room*,2> config();
        Room* finalRoom;
    public:
        Game(string name);
        Student * getPlayer();
        Room* getcurrentRoom();
        Room* getFinalRoom();

};