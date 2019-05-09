#include <iostream>
#include "List.h"

int main() {
    try {
        List list1(10, 5.0);
        List list2(10, 5.0);
        
        for ( int i = 10; i > 0; i-- ) {
            list1.push_back(i);
        }

        for ( int i = 9; i > 0; i-- ) {
            list2.push_back(i);
        }

        std::cout << list1;
        std::cout << list1.size() << std::endl;

        std::cout << list2;
        std::cout << list2.size() << std::endl;


        int result = list1 == list2;
        if ( result ) {
            std::cout << "Lists are equal!" << std::endl;
        } else {
            std::cout << "Lists are not equal!" << std::endl;
        }
        // std::cout << result << std::endl;
        // std::cout << list;
        
        // list.insert(5, 2);
        // std::cout << list;
        
        // list.pop_back();
        // std::cout << list;
        
        // int indexFindValue = list.find(5);
        // std::cout << indexFindValue << std::endl;
        
        // list.sort();
        // std::cout << list;
        
        // std::cout << list[3] << std::endl;
        
        // list.erase(0);
        // list.erase(0);
        // list.erase(0);
        // std::cout << list.max_size() << std::endl;
        // std::cout << list.size() << std::endl;
        // std::cout << list;

        
        // list.push_back(-100);
        // std::cout << list.size() << std::endl;
        // std::cout << list.max_size() << std::endl;
        
        // list.push_back(555);
        // std::cout << list.size() << std::endl;
        // std::cout << list.max_size() << std::endl;
        // std::cout << list;
        
        // for ( int i = 0; i < 7; i++ ) {
        //     list.pop_back();
        // }
        
        // std::cout << list;
    } catch ( ZeroLenException& e ) {
        std::cout << "Shlyapa! List size is = 0" << std::endl;
    } catch ( OutOfMemoryException& e ){
        std::cout << "Shlyapa! Memmory re/allocation error!" <<  std::endl;
    }





    return 0;
}