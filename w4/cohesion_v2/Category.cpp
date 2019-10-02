#include "Category.h"

Category::Category(const std::string& categoryName) : Basic(categoryName) {
    categoryUID += 1;
    this->id = categoryUID;
    allCategories.insert(this);
};

Category::~Category() {
    for ( std::set<Basic*>::iterator it =  this->connectionList.begin(); it != this->connectionList.end(); it++ ) {
        dynamic_cast<Item*>(*it)->changeCategory();
    }
    this->connectionList.clear();
    allCategories.erase(this);
};

const std::set<Category*>& Category::getAllCategories() {
    return allCategories;
};

int Category::categoryUID = 0;
std::set<Category*> Category::allCategories;