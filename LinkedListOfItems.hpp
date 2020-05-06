#ifndef LinkedListOfItems_hpp
#define LinkedListOfItems_hpp
#include "Item.hpp"
#include "ItemNode.hpp"


class Item;
class ItemNode;
using namespace std;
class LinkedListOfItems
{
    private: 
        ItemNode* head;
        int count;
        

    public:
        LinkedListOfItems();
        void addFront(Item* s);
        Item* getAtIndex(int index);
        Item* removeAtIndex(int index);
        int indexOf(Item* s); //returns index or -1 if not found
        void display();
        void removeFront();
        int getCount();
        int findIndexByName(string name);
        };

#endif