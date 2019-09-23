#include "Order.h"

Order::Order(Customer* customer, Item* item) : customer(customer) {
    orderUID += 1;
    this->orderID = orderUID;
    this->allItems.insert(item);
    allOrders.insert(this);
};

Order::~Order() {

};