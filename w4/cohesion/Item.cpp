#include "Item.h"

int Item::itemUID = 0;
std::set<Item*> Item::allItems;

Item::Item(const std::string& itemName, Category* category) : itemName(itemName), category(category) {
    itemUID += 1;
    this->itemID = itemUID;
    this->category->addItem(this);
    allItems.insert(this);
}

Item::~Item() {
    for ( std::set<Order*>::iterator it = this->allOrders.begin(); it != this->allOrders.end(); it++ ) {
        (*it)->removeItem(this);
    }
    this->category->removeItem(this);
    allItems.erase(this);
};

const std::set<Item*>& Item::getAllItems() {
    return allItems;
};

const std::string& Item::getItemName() const {
    return this->itemName;
};

const std::set<Order*>& Item::getAllOrders() const {
    return this->allOrders;
};