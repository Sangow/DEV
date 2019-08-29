#include "Soldier.h"

Soldier::Soldier(const char* charName) : Unit(charName, "Soldier") {
    this->state = new HumanState(120, 1, 1);
    this->weapon = new Sword(this);
};

Soldier::~Soldier() {};