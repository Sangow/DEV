#include "Passport.h"

int main() {
    try {

    } catch (PassportException e) {
        std::cout << e.text << std::endl;
    }
    return 0;
}