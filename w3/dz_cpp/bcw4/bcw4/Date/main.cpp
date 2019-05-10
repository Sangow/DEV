#include <iostream>
#include "Date.h"

int main() {
    try {
        Date date(28, 12, 1997);

        std::cout << date << std::endl;

    } catch ( InvalidDate e ) {
        std::cout << e.text << std::endl;
    }
    return 0;
}