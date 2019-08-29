#include "Berserker.h"

Berserker::Berserker(char* charName) : Unit(charName, "Berserker") {
    this->state = new BerserkerState(150);
    this->weapon = new TwoHandedSword(this);
};

Berserker::~Berserker() {};