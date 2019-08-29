#include "Staff.h"

Staff::Staff(Unit* owner, State* ownerState) : Weapon("Staff", owner) {
    this->dmg = this->owner->get
};

Staff::~Staff() {};

void Staff::cast(const char* spellName, Unit* enemy) {

};