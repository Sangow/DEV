#include "Order.h"

Order::Order(Item* item, Customer* customer) : Basic("Order"), customer(customer) {
    orderUID += 1;
    this->id = orderUID;
    this->customer->addConnection(this);
    this->addConnection(item);
    allOrders.insert(this);
};

Order::~Order() {
    for ( std::set<Basic*>::iterator it = this->connectionList.begin(); it != this->connectionList.end(); it++ ) {
        (*it)->removeConnection(this);
    }
    this->connectionList.clear();
    this->customer->removeConnection(this);
    allOrders.erase(this);
};

const Customer& Order::getCustomer() const {
    return *(this->customer);
};

const std::set<Order*>& Order::getAllOrders() {
    return allOrders;
};

void Order::addConnection(Basic* newConnection) {
    this->connectionList.insert(newConnection);
    newConnection->Basic::addConnection(this);
};

void Order::removeConnection(Basic* connection) {
    connection->Basic::removeConnection(this);
    this->connectionList.erase(connection);
};

int Order::orderUID = 0;
std::set<Order*> Order::allOrders;