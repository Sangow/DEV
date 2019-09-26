#ifndef ITEM_H
#define ITEM_H

#include "Basic.h"
#include "Category.h"

class Item : public Basic {
    private:
        static int itemUID;
        static std::set<Item*> allItems;
        Category* category;
    public:
        Item(const std::string& itemName, Category* category);
        ~Item();

        static const std::set<Item*>& getAllItems();

        virtual void addConnection(Basic* newConnection) override;
        virtual void removeConnection(Basic* connection) override;
};

#endif // ITEM_H