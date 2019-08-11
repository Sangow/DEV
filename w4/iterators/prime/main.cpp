#include "Prime.h"

int main() {
    Prime p(10);

    for ( ; !p.isOver(); p++ ) {
        std::cout << *p << std::endl;
    }

    // This is mosh`niy kostil`!!!!!
    p.resetOver();

    for ( ; !p.isOver(); p-- ) {
        std::cout << *p << std::endl;
    }
}