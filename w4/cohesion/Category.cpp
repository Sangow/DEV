#include "Category.h"

int Category::categoryUID = 0;
std::set<Category*> Category::allCategories;

Category::Category(const std::string& categoryName) : categoryName(categoryName) {
    categoryUID += 1;
    this->categoryID = categoryUID;
    allCategories.insert(this);
};

Category::~Category() {};

void Category::addItem(Item* newItem) {
    this->allItems.insert(newItem);
};

void Category::removeItem(Item* item) {
    this->allItems.erase(item);
};

const std::set<Category*>& Category::getAllCategories() {
    return allCategories;
};

const std::set<Item*>& Category::getAllItems() const {
    return this->allItems;
};

const std::string& Category::getCategoryName() const {
    return this->categoryName;
};
