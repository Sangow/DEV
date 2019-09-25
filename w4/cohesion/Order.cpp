#include "Order.h"

Order::Order(Customer* customer, Item* item) : customer(customer) {
    orderUID += 1;
    this->orderID = orderUID;
    this->allItems.insert(item);
    allOrders.insert(this);
    this->customer->addOrder(this);
};

Order::~Order() {
    for ( std::set<Item*>::iterator it = this->allItems.begin(); it != this->allItems.end(); it++ ) {
        (*it)
    }
    this->customer->removeOrder(this);
    allOrders.erase(this);
};

const std::set<Order*>& getAllOrders() {
    return allOrders;
};

const Customer& getCustomer() const {
    return this->customer;
};

const std::set<Item*>& getAllItems() const {
    return this->allItems;
};

void addItem(Item* newItem) {
    this->allItems.insert(newItem);
};
void removeItem(Item* item) {
    this->allItems.erase(item);
};