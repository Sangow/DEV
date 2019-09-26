#ifndef CATEGORY_H
#define CATEGORY_H

#include "Basic.h"

class Category : public Basic {
    private:
        static int categoryUID;
        static std::set<Category*> allCategories;
    public:
        Category(const std::string& categoryName);
        ~Category();

        static const std::set<Category*>& getAllCategories();

        // const std::set<Item*>& getAllItems() const;

        // void addItem(Item* newItem);
        // void removeItem(Item* item);
};

#endif // CATEGORY_H