#include "Customer.h"

int Customer::customerUID = 0;
std::set<Customer*> Customer::allCustomers;

Customer::Customer(const std::string& customerName) : customerName(customerName) {
    customerUID += 1;
    this->customerID = customerUID;
    allCustomers.insert(this);
};

Customer::~Customer() {};

const std::set<Customer*>& Customer::getAllCustomers() {
    return allCustomers;
};

const std::set<Order*> Customer::getAllOrders() const {
    return this->allOrders;
};

void Customer::addOrder(Order* newOrder) {
    this->allOrders.insert(newOrder);
};

void Customer::removeOrder(Order* order) {
    this->allOrders.erase(order);
};

