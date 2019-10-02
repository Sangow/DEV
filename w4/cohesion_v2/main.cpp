#include "Category.h"
#include "Item.h"
#include "Order.h"
#include "Customer.h"

int main() {
    Category* cars = new Category("Cars");
    Category* weapons = new Category("Weapons");

    Customer* man = new Customer("Grisha");
    

    Item* mers = new Item("Mers", cars);
    Item* mar = new Item("Marusya", cars);
    Item* bmw = new Item("BMW", cars);
    Item* nissan = new Item("Nissan", cars);

    Item* ak = new Item("AK-74", weapons);
    Item* jav = new Item("Javeline", weapons);
    Item* baz = new Item("Bazooka", weapons);
    Item* zal = new Item("Zalupa", weapons);

    // std::cout << *cars << std::endl;
    // cars->printConnectionList();

    // delete mers;

    // std::cout << *cars << std::endl;
    // cars->printConnectionList();
    
    Order* ord1 = new Order(mar, man);
    Order* ord2 = new Order(zal, man);

    ord1->addConnection(bmw);
    ord1->addConnection(jav);
    ord1->addConnection(baz);
    ord1->addConnection(zal);

    ord2->addConnection(zal);
    ord2->addConnection(baz);
    ord2->addConnection(jav);
    ord2->addConnection(bmw);


    // for ( std::set<Order*>::const_iterator it = Order::getAllOrders().begin(); it != Order::getAllOrders().end(); it++ ) {
    //     std::cout << **it << std::endl;
    //     (*it)->printConnectionList();
    // }

    // ord1->removeConnection(baz);

    // for ( std::set<Order*>::const_iterator it = Order::getAllOrders().begin(); it != Order::getAllOrders().end(); it++ ) {
    //     std::cout << **it << std::endl;
    //     (*it)->printConnectionList();
    // }

    for ( std::set<Item*>::const_iterator it = Item::getAllItems().begin(); it != Item::getAllItems().end(); it++ ) {
        std::cout << **it << std::endl;
        (*it)->printConnectionList();
    }
    
    zal->removeConnection(ord1);

    std::cout << "=========" << std::endl;

    for ( std::set<Item*>::const_iterator it = Item::getAllItems().begin(); it != Item::getAllItems().end(); it++ ) {
        std::cout << **it << std::endl;
        (*it)->printConnectionList();
    }

    std::cout << *cars << std::endl;


    std::cout << "=========" << std::endl;

    for ( std::set<Category*>::const_iterator it = Category::getAllCategories().begin(); it != Category::getAllCategories().end(); it++ ) {
        std::cout << *it << std::endl;
    }

    return 0;
}