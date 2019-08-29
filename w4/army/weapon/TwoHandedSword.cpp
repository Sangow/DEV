#include "TwoHandedSword.h"

TwoHandedSword::TwoHandedSword(Unit* owner) : Weapon("TwoHandedSword", owner) {
    this->dmg = this->owner->getStrength() * 35;
};

TwoHandedSword::~TwoHandedSword() {};