#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <set>
#include "Category.h"
#include "Order.h"

class Order;

class Item {
    private:
        static int itemUID;
        static std::set<Item*> allItems;

        std::set<Order*> allOrders;
        Category* category;
        std::string itemName;
    public:
        Item(const std::string& itemName, Category* category);
        ~Item();

        static const std::set<Item*>& getAllItems() const;
        const std::set<Order*>& getAllOrders() const;
};

#endif // ITEM_H