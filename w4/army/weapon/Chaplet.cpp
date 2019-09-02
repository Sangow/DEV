#include "Chaplet.h"

Chaplet::Chaplet(Unit* owner) : Weapon("Chaplet", owner) {
    this->dmg = this->owner->getStrength() * this->owner->getAgility() * 666;
};

Chaplet::~Chaplet() {};