#include <iostream>
#include "car.h"

int main() {
    Car* car = new Car();

    std::cout << car->getMaxFuel() << std::endl;
    std::cout << car->getCurrentFuel() << std::endl;
    std::cout << car->getConsumption() << std::endl;

    car->setMaxFuel(200);
    car->setCurrentFuel(165.6);
    car->setConsumption(1.3);

    std::cout << car->getMaxFuel() << std::endl;
    std::cout << car->getCurrentFuel() << std::endl;
    std::cout << car->getConsumption() << std::endl;

    delete car;
    
    return 0;
}