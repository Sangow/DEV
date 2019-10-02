#ifndef CATEGORY_H
#define CATEGORY_H

#include "Basic.h"
#include "Item.h"

class Item;

class Category : public Basic {
    private:
        static int categoryUID;
        static std::set<Category*> allCategories;
    public:
        Category(const std::string& categoryName);
        ~Category();

        static const std::set<Category*>& getAllCategories();
};

#endif // CATEGORY_H