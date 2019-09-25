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

int Category::categoryUID = 0;
std::set<Category*> Category::allCategories;