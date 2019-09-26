#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Basic.h"

class Customer : public Basic {
    private:
        static int customerUID;
        static std::set<Customer*> allCustomers;
    public:
        Customer(const std::string& customerName);
        ~Customer();

        static const std::set<Customer*>& getAllCustomers();
};

#endif  // CUSTOMER_H