#include "Soldier.h"

Soldier::Soldier(char* charName) : Unit(charName, "Soldier") {
    this->state = new UnitState(200);
    this->weapon = new Sword(this);
};

Soldier::~Soldier() {};