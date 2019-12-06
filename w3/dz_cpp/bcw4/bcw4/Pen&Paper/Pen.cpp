#include <iostream>
#include "Pen.h"

Pen::Pen(int inkCapacity) {
    this->inkCapacity = inkCapacity;
    this->inkAmount = 0;
}

Pen::~Pen() {}

int Pen::getInkAmount() const {
    return this->inkAmount;
}

int Pen::getInkCapacity() const {
    return this->inkCapacity;
}

void Pen::write(Paper& paper, const std::string& message) {
    if ( this->inkAmount == 0 ) {
        throw OutOfInk();
    } 
    if ( this->inkAmount < message.size() ) {
        int newLength = this->inkAmount;

        this->inkAmount = 0;
        paper.addContent(message.substr(0, newLength));
        return;
    }
    this->inkAmount -= message.size();
    paper.addContent(message);
}

void Pen::refill() {
    this->inkAmount = this->inkCapacity;
}