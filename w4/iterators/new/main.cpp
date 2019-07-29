#include "Fibonacci.h"

int main() {
    Fibonacci f(10);

    for ( ; !f.isOver(); f++ ) {
        std::cout << *f << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    // f--;
    for ( ; !f.isOver(); f-- ) {
        std::cout << *f << std::endl;
    }

    // f++;
    // f++;
    // std::cout << *f << std::endl;


    return 0;
}