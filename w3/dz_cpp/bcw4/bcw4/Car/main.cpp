#include <iostream>
#include "Point.h"
#include "Car.h"

int main() {
    try{
        Car car;

        std::cout << car << std::endl;

        car.refill(50);

        std::cout << "Fuel amount: " << car.getFuelAmount() << std::endl;

        car.drive(Point(5, 11));

        std::cout << car << std::endl;

        car.drive(10, 20);

        std::cout << car << std::endl;

        car.refill(50);

    } catch ( OutOfFuel e ) {
        std::cout << "Error! Need to refill() car!" << std::endl;
    } catch ( ToMuchFuel e ) {
        std::cout << "Error! You refill() too much fuel!";
    }

    return 0;
}