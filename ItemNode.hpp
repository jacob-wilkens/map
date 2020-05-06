#ifndef StudentNode_hpp
#define StudentNode_hpp

#include "Item.hpp"
class Item;

class ItemNode
{
    private:
        Item* payload;
        ItemNode* nextNode;

    public:
        ItemNode(Item* payload);
        void setNextNode(ItemNode* n);
        Item* getPayload();
        ItemNode* getNextNode();
};
#endif