#include <iostream>
#include "CustomVector.h"

int main() {
   CustomVector<std::string>* lst = new CustomVector<std::string>(1000, 0);

    lst->push_back("a");
    lst->push_back("b");
    // lst->push_back("c");
    // lst->push_back("d");

    for ( int i = 0; i < lst->size(); i++ ) {
        std::cout << (*lst)[i] << std::endl;
    }

    std::cout << "--------" << std::endl;

    lst->pop_back();
    

    for ( int i = 0; i < lst->size(); i++ ) {
        std::cout << (*lst)[i] << std::endl;
    }

    std::cout << "--------" << std::endl;

    lst->push_back("koko");
    // lst->push_back("koko");
    
    for ( int i = 0; i < lst->size(); i++ ) {
        std::cout << (*lst)[i] << std::endl;
    }

    delete lst;

    return 0;
}