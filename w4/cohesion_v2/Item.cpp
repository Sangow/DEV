#include "Item.h"

Item::Item(const std::string& itemName, Category* category) : Basic(itemName), category(category) {
    itemUID += 1;
    this->id = itemUID;
    this->category->addConnection(this);
    allItems.insert(this);
};

Item::~Item() {
    for ( std::set<Basic*>::iterator it = this->connectionList.begin(); it != this->connectionList.end(); it++ ) {
        (*it)->removeConnection(this);
    }
    this->connectionList.clear();
    this->category->removeConnection(this);
    allItems.erase(this);
};

const std::set<Item*>& Item::getAllItems() {
    return allItems;
};

void Item::addConnection(Basic* newConnection) {
    try {
        throw PermissionDeniedException();
    } catch (PermissionDeniedException e) {
        std::cout << "Item: " << this->name << e.message << std::endl;
    }
};

void Item::removeConnection(Basic* connection) {
    try {
        throw PermissionDeniedException();
    } catch (PermissionDeniedException e) {
        std::cout << "Item: " << this->name << e.message << std::endl;
    }
};

void Item::changeCategory(Category* newCategory) {
    this->category = newCategory;
};

int Item::itemUID = 0;
std::set<Item*> Item::allItems;