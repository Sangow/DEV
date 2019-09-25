#ifndef ITEM_H
#define ITEM_H

#include "Basic.h"
#include "Category.h"

class Item : public Basic {
    private:
        static int itemUID;
        static std::set<Item*> allItems;
    public:
        Item(const std::string& itemName, Category* category);
        ~Item();

        static const std::set<Item*>& getAllItems();
};

#endif // ITEM_H