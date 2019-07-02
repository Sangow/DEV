#include "Identifiable.h"

Identifiable::Identifiable() {
    this->uID = nextUID;
    nextUID += 1;
}

int Identifiable::getNextUID(){
    return nextUID;
}

int Identifiable::getUID() const {
    return this->uID;
}

int Identifiable::nextUID = 0;