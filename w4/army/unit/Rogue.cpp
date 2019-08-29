#include "Rogue.h"

Rogue::Rogue(char* charName) : Unit(charName, "Rogue") {
    this->state = new UnitState(90);
    this->weapon = new Dagger(this);
};

Rogue::~Rogue() {};