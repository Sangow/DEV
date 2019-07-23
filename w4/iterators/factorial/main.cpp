#include "Factorial.h"

int main() {

    Factorial f(20);

    for ( ; !f.over(); f++ ) {
        std::cout << *f << std::endl;
    }

    std::cout << "----------------" << std::endl;

    // f.next();

    // std::cout << *f << std::endl;



    return 0;
}