#include "Range.h"

int main() {
    // Range range(-10, 10, 3);

    // for ( ; range < range.end(); range++ ) {
    //     std::cout << *range << std::endl;
    // }
    // std::cout << *range << std::endl;

    Range* ari = new Range(-10, 10, 3);

    for ( ; *ari < ari->end(); (*ari)++ ) {
        std::cout << **ari << std::endl;
    }
    std::cout << **ari << std::endl;

    return 0;
}