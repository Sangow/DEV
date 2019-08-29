#include "Sword.h"

Sword::Sword(Unit* owner) : Weapon("Sword", owner) {
    this->dmg = this->owner->getStrength() * 25;
};

Sword::~Sword() {};