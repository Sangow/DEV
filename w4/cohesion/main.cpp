#include "Category.h"
#include "Item.h"
#include <set>

int main() {
    Category* cars = new Category("Cars");
    Category* pens = new Category("Pens");

    Item* car1 = new Item("Lambo", cars);
    Item* car2 = new Item("Mers", cars);
    Item* car3 = new Item("Zalupa", cars);

    Item* pen1 = new Item("Obreey", pens);
    Item* pen2 = new Item("Parker", pens);

    for ( std::set<Category*>::const_iterator cat = Category::getAllCategories().begin(); cat != Category::getAllCategories().end(); cat++ ) {
        std::cout << (*cat)->getCategoryName() << std::endl;;
        for ( std::set<Item*>::const_iterator it = (*cat)->getAllItems().begin(); it != (*cat)->getAllItems().end(); it++ ) {
            std::cout << "---" << (*it)->getItemName() << std::endl;
        }
    }

    delete car2;

    for ( std::set<Category*>::const_iterator cat = Category::getAllCategories().begin(); cat != Category::getAllCategories().end(); cat++ ) {
        std::cout << (*cat)->getCategoryName() << std::endl;;
        for ( std::set<Item*>::const_iterator it = (*cat)->getAllItems().begin(); it != (*cat)->getAllItems().end(); it++ ) {
            std::cout << "---" << (*it)->getItemName() << std::endl;
        }
    }

    return 0;
}