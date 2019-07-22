#include "Range.h"

int main() {
    // Range range(-10, 10, 3);

    // for ( ; range < range.end(); range++ ) {
    //     std::cout << *range << std::endl;
    // }
    // std::cout << *range << std::endl;

    Range ari(-10, 21, 4);

    for ( ; !ari.over(); ari++ ) {
        std::cout << *ari << std::endl;
    }

    std::cout << "------------------------" << std::endl;


    // for ( ; !ari.over(); ari-- ) {
    //     std::cout << *ari << std::endl;
    // }


    ari.changeIndex(4);

    std::cout << *ari << std::endl;

    ari.changeIndex(0);

    std::cout << *ari << std::endl;

    return 0;
}