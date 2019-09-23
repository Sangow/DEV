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
    this->category->removeItem(this);
};

const std::set<Item*>& Item::getAllItems() {
    return allItems;
};

const std::string& Item::getItemName() const {
    return this->itemName;
};

const std::set<Order*>& getAllOrders() const {
    return this->allOrders;
};