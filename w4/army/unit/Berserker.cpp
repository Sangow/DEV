#include "Berserker.h"

Berserker::Berserker(const std::string& charName) : Unit(charName, "Berserker") {
    this->state = new BerserkerState();
    this->weapon = new TwoHandedSword(this);
};

Berserker::~Berserker() {};