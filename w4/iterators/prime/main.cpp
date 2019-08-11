#include "Prime.h"

int main() {
    Prime p(10);

    for ( ; !p.isOver(); p++ ) {
        std::cout << *p << std::endl;
    }

    // Does not work!
    // for ( ; !p.isOver(); p-- ) {
    //     std::cout << *p << std::endl;
    // }

    std::cout << "-----------------" << std::endl;

    std::cout << p.index << std::endl;
    std::cout << p.currCapacity << std::endl;
    std::cout << p.maxCapacity << std::endl;
}