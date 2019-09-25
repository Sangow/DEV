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
        std::string customerName;
    public:
        Customer(const std::string& customerName);
        ~Customer();

        static const std::set<Customer*>& getAllCustomers();
        const std::set<Order*> getAllOrders() const;

        void addOrder(Order* newOrder);
        void removeOrder(Order* order);
};

#endif // CUSTOMER_H