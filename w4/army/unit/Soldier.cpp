#include "Soldier.h"

Soldier::Soldier(const std::string& charName) : Unit(charName, "Soldier") {
    this->state = new SoldierState();
    this->weapon = new Sword(this);
};

Soldier::~Soldier() {};