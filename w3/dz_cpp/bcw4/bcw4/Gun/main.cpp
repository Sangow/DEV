#include <iostream>
#include "Gun.h"

int main() {
    try {
        Gun fort("Fort", 10);
        std::cout << fort << std::endl;

        fort.reload();
        std::cout << fort << std::endl;

        fort.prepare();
        fort.prepare();


        fort.shoot();
        fort.shoot();
        fort.shoot();
        fort.shoot();
        fort.shoot();
        fort.shoot();
        fort.shoot();
        fort.shoot();
        fort.shoot();
        fort.shoot();
        std::cout << fort << std::endl;

        fort.shoot();

        std::cout << fort << std::endl;

        return 0;
    } catch ( OutOfRounds& e ) {
        std::cout << "Error! You should reload the gun!" << std::endl;
    } catch ( NotReady& e ) {
        std::cout << "Gun is not ready!" << std::endl;
    }
}