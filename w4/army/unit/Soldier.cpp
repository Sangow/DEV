#include "Soldier.h"

Soldier::Soldier(const char* charName) : Unit(charName, "Soldier") {
    this->state = new SoldierState();
    this->weapon = new Sword(this);
};

Soldier::~Soldier() {};