#include "Vampire.h"

Vampire::Vampire(const std::string& charName) : Unit(charName, "Vampire") {
    this->state = new VampireState();
    this->weapon = new Claws(this);
    this->ability = new VampireAbility(this);
};

Vampire::~Vampire() {};