#include "Student.hpp"
#include "Door.hpp"
#include "Room.hpp"
#include <array>
using namespace std;

class Game{
    private:
        Student* player;
        Room* currentRoom;
        array<Room*,2> config();
        Room* finalRoom;
        bool inputCheck(string input, DirectionList* directions);
    public:
        Game(string name);
        void begin();

};