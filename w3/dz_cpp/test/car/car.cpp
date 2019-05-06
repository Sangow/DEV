#include <iostream>
#include "car.h"

Car::Car() {
    this->maxFuel       = 100;
    this->currentFuel   = 100;
    this->consuption    = 0.8;
    this->model         = new char[50];
}

Car::~Car() {
    delete this->model;
}

double Car::getMaxFuel() const {
    return this->maxFuel;
}

double Car::getCurrentFuel() const{
    return this->currentFuel;
}

double Car::getConsumption() const{
    return this->consuption;
}

void Car::setMaxFuel(double maxFuel) {
    this->maxFuel = maxFuel;
}

void Car::setCurrentFuel(double currentFuel) {
    if ( currentFuel > this->maxFuel ) {
        currentFuel = this->maxFuel;
    } else if ( currentFuel < 0 ) {
        currentFuel = 0;
    }
    this->currentFuel = currentFuel;
}

void Car::setConsumption(double consuption) {
    this->consuption = consuption;
}