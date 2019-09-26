#include "Category.h"

Category::Category(const std::string& categoryName) : Basic(categoryName) {
    categoryUID += 1;
    this->id = categoryUID;
    allCategories.insert(this);
};

Category::~Category() {
    // for ( std::set<> ) {

    // }
    allCategories.erase(this);
};

const std::set<Category*>& Category::getAllCategories() {
    return allCategories;
};

// const std::set<Item*>& Category::getAllItems() const {
//     return this->getConnectionList();
// };


// void Category::addItem(Item* newItem) {
//     this->addConnection(newItem);
// };

// void Category::removeItem(Item* item) {
//     this->removeConnection(item);
// };

int Category::categoryUID = 0;
std::set<Category*> Category::allCategories;