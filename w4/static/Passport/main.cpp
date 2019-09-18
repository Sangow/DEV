#include "Passport.h"// template class Range<float>;
// template class Range<double>;

int main() {
    try {
        Passport* p = new Passport();

        std::cout << *p << std::endl;
    } catch (PassportException e) {
        std::cout << e.text << std::endl;
    }
    return 0;
}