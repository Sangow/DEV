#include "Mace.h"

Mace::Mace(Unit* owner) : Weapon("Mace", owner) {
    this->dmg = this->owner->getStrength() * 30;
};

Mace::~Mace() {};