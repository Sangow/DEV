#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <set>
#include "Item.h"

class Category {
    private:
        static int categoryUID;
        static std::set<Category*> allCategories;

        std::set<Item*> allItems;
        std::string categoryName;
    public:
        Category(const std::string& categoryName);
        ~Category();

        void addItem(Item* newItem);
        void removeItem(Item* item);

        static const std::set<Category*>& getAllCategories() const;
        const std::set<Item*>& getAllItems() const;
};

#endif // CATEGORY_H