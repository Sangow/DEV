#include "Customer.h"

Customer::Customer(const std::string& customerName) : Basic(customerName) {
    customerUID += 1;
    this->id = customerUID;
    allCustomers.insert(this);
};

Customer::~Customer() {
    // delete all this->orders
    // for () {

    // }
    allCustomers.erase(this);
};

const std::set<Customer*>& Customer::getAllCustomers() {
    return allCustomers;
};

int Customer::customerUID = 0;
std::set<Customer*> Customer::allCustomers;