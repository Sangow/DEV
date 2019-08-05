#include "Fibonacci.h"

int main() {
    Fibonacci f(92);

    for ( ; !f.isOver(); f++ ) {
        std::cout << *f << std::endl;
    }

    std::cout << "-----------------" << std::endl;
    for ( ; !f.isOver(); f-- ) {
        std::cout << *f << std::endl;
    }

    return 0;
}