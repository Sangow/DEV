#include "Berserker.h"

Berserker::Berserker(const char* charName) : Unit(charName, "Berserker") {
    this->state = new BerserkerState();
    this->weapon = new TwoHandedSword(this);
};

Berserker::~Berserker() {};