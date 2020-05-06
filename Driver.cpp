#include <iostream>
#include "Game.hpp"
#include "Item.hpp"
#include "LinkedListOfItems.hpp"
using namespace std;

int main(){
    string name;
    cout << "Enter the name of the player: ";
    cin >> name;
    cout << "\n";
    Game* g = new Game(name);
    g->begin();
    cout << "You win\n\n";


}