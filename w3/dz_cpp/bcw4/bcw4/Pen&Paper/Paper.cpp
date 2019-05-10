#include <iostream>
#include "Paper.h"

Paper::Paper(int maxSymbols) {
    this->maxSymbols = maxSymbols;
    this->symbols = 0;
    this->content = "";
}

Paper::~Paper() {}

int Paper::getMaxSymbols() const {
    return this->maxSymbols;
}

int Paper::getSymbols() const {
    return this->symbols;
}

void Paper::addContent(const std::string& message) {
    if ( this->symbols == this->maxSymbols ) {
        throw OutOfSpace();
    }
    int maxInputSymbols = this->maxSymbols - this->symbols;

    if ( maxInputSymbols < message.size() ) {
        this->symbols = this->maxSymbols;
        this->content += message.substr(0, maxInputSymbols);
        return;
    }
    this->symbols += message.size();
    this->content += message;
}

void Paper::show() const {
    std::cout << "Paper: " << this->symbols << "/" << this->maxSymbols << "\n";
    std::cout << this->content << std::endl;
}