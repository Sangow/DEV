#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <set>
#include "Item.h"

class Item;

class Category {
    private:
        static int categoryUID;
        static std::set<Category*> allCategories;

        int categoryID;
        std::set<Item*> allItems;
        std::string categoryName;
    public:
        Category(const std::string& categoryName);
        ~Category();

        void addItem(Item* newItem);
        void removeItem(Item* item);

        static const std::set<Category*>& getAllCategories();
        const std::set<Item*>& getAllItems() const;

        const std::string& getCategoryName() const;
};

#endif // CATEGORY_H