#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <set>
#include "Order.h"

class Order;

class Customer {
    private:
        static int customerUID;
        static std::set<Customer*> allCustomers;

        int customerID;
        std::set<Order*> allOrders;
    public:
        Customer();
        ~Customer();

        static const std::set<Customer*>& getAllCustomers() const;
        const std::set<Order*> getAllOrders() const;
};

#endif // CUSTOMER_H