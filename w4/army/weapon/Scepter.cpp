#include "Scepter.h"

Scepter::Scepter(Unit* owner) : Weapon("Scepter", owner) {
    this->dmg = this->owner->getStrength() * this->owner->getAgility() * 25;
};

Scepter::~Scepter() {};