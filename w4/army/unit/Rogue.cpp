#include "Rogue.h"

Rogue::Rogue(char* charName) : Unit(charName, "Rogue") {
    this->state = new HumanState(75, 0.5, 1.5);
    this->weapon = new Dagger(this);
};

Rogue::~Rogue() {};