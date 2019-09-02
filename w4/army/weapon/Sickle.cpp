#include "Sickle.h"

Sickle::Sickle(Unit* owner) : Weapon("Sickle", owner) {
    this->dmg = this->owner->getStrength() * this->owner->getAgility() * 25;
};

Sickle::~Sickle() {};