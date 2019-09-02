#include "Staff.h"

Staff::Staff(Unit* owner) : Weapon("Staff", owner) {
    this->dmg = this->owner->getStrength() * this->owner->getAgility() * 30;
};

Staff::~Staff() {};