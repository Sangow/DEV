#ifndef ORDER_H
#define ORDER_H

#include "Basic.h"
#include "Item.h"
#include "Customer.h"

class Order : public Basic {
    private:
        static int orderUID;
        static std::set<Order*> allOrders;
        Customer* customer;
    public:
        Order(Item* item, Customer* customer);
        ~Order();

        const Customer& getCustomer() const;
        static const std::set<Order*>& getAllOrders();

        virtual void addConnection(Basic* newConnection) override;
        virtual void removeConnection(Basic* connection) override;
};

#endif // ORDER_H