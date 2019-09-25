#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <set>
#include "Customer.h"
#include "Item.h"
#include "Order.h"

class Item;
class Customer;

class Order {
    private:
        static int orderUID;
        static std::set<Order*> allOrders;

        int orderID;
        std::set<Item*> allItems;
        Customer* customer;
    public:
        Order(Customer* customer, Item* item);
        ~Order();

        static const std::set<Order*>& getAllOrders();
        const Customer& getCustomer() const;
        const std::set<Item*>& getAllItems() const;

        void addItem(Item* newItem);
        void removeItem(Item* item);
};

#endif // ORDER_H