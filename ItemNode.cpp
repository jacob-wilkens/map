#include "ItemNode.hpp"

ItemNode::ItemNode(Item* payload)
{
    this->payload = payload;
    this->nextNode = 0;
}

void ItemNode::setNextNode(ItemNode* n)
{
    this->nextNode = n;
}

Item* ItemNode::getPayload()
{
    return this->payload;
}

ItemNode* ItemNode::getNextNode()
{
    return this->nextNode;
}