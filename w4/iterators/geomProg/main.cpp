#include "GeomProg.h"


int main() {
    GeomProg<int> gp(2, 7, 2);

    for ( ; !gp.over(); gp++ ) {
        std::cout << *gp << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    // std::cout << gp[10] << std::endl;

    // gp.changeIndex(14);

    // std::cout << *gp << std::endl;
        std::cout << *gp << std::endl;
    

    return 0;
}