#include "Item.h"

Item::Item(const std::string& itemName, Category* category) : Basic(itemName) {
    itemUID += 1;
    this->id = itemUID;
    this->category->addConnection(this);
    allItems.insert(this);
};

Item::~Item() {
    this->category->removeConnection(this);
    allItems.erase(this);
};

const std::set<Item*>& getAllItems() const {
    return allItems;
};


int Item::itemUID = 0;
std::set<Item*> Item::allItems;