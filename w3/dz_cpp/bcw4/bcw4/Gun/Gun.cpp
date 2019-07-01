#include <iostream>
#include "Gun.h"

Gun::Gun(const std::string& model, int capacity) {
    this->amount = 0;
    this->capacity = capacity;
    this->isReady = false;
    this->model = model;
    this->totalShots = 0;
}

Gun::~Gun() {}

int Gun::getAmount() const {
    return this->amount;
}

int Gun::getCapacity() const {
    return this->capacity;
}

bool Gun::ready() const {
    return this->isReady;
}

const std::string& Gun::getModel() const {
    return this->model;
}

int Gun::getTotalShots() const {
    return this->totalShots;
}

void Gun::prepare() {
    if ( !this->isReady )
        this->isReady = true;
}

void Gun::reload() {
    this->amount = this->capacity;
    std::cout << "Gun reloaded!" <<std::endl;
}

void Gun::shoot() {
    if ( !this->ready() ) {
        throw NotReady();
    }

    if ( this->amount == 0 ) {
        throw OutOfRounds();
    }
    std::cout <<"Bang!" << std::endl;
    this->amount -= 1;
    this->totalShots += 1;
}

std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    out << "Gun model: " << gun.getModel() << "\n";
    out << "rounds/capacity: " << gun.getAmount() << "/" << gun.getCapacity() << "\n";
    out << "Total shots: " << gun.getTotalShots() << "\n";
    out << "Ready gun: " << gun.ready() << std::endl;
    return out;
}