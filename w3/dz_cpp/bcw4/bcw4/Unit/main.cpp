#include <iostream>
#include "Unit.h"

int main() {
    Unit barbarian("Barbarian", 200, 179);
    Unit knight("Knight", 180, 25);

    try {
    
        std::cout << barbarian << std::endl;
        std::cout << knight << std::endl;
        
        barbarian.attack(knight);
        
        std::cout << barbarian << std::endl;
        std::cout << knight << std::endl;

        knight.addHitPoints(200);

        std::cout << barbarian << std::endl;
        std::cout << knight << std::endl;

    } catch ( UnitIsDead e) {
        std::cout << barbarian << std::endl;
        std::cout << knight << std::endl;
    }

    return 0;
}