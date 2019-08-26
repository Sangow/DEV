#include "Vampire.h"

Vampire::Vampire(char* charName) : Unit(charName, "Vampire") {
    this->state = new VampireState(90);
    this->weapon = new Claws(this);
};

Vampire::~Vampire() {};