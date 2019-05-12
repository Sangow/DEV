 #include <iostream>
#include "Car.h"
#include "Point.h"

Car::Car(double capacity, double consumption, const Point& location, const std::string& model) {
    this->fuelAmount = 0;
    this->fuelCapacity = capacity;
    this->fuelConsumption = consumption;
    this->location = location;
    this->model = model;
}

Car::~Car() {}

double Car::getFuelAmount() const {
    return this->fuelAmount;
}

double Car::getFuelCapacity() const {
    return this->fuelCapacity;
}

double Car::getFuelConsumption() const {
    return this->fuelConsumption;
}

const Point& Car::getLocation() const {
    return this->location;
}

const std::string& Car::getModel() const {
    return this->model;
}

void Car::drive(const Point& destination) {
    int fuelNeeded = this->location.distance(destination) * this->fuelConsumption;

    if ( fuelNeeded > this->fuelAmount ) {
        throw OutOfFuel();
    }
    this->fuelAmount -= fuelNeeded;
    this->location = destination;
}

void Car::drive(double x, double y) {
    Point destination(x, y);
    this->drive(destination);
}

void Car::refill(double fuel) {
    if ( this->fuelAmount + fuel > this->fuelCapacity ) {
        throw ToMuchFuel();
    }
    this->fuelAmount += fuel;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Car model: " << car.getModel() << "\n";
    out << "Consumption: " << car.getFuelConsumption() << "\n";
    out << "Fuel: " << car.getFuelAmount() << "/" << car.getFuelCapacity() << "\n";
    out << "Location: " << car.getLocation();
    return out;
}