#include <iostream>
#include "Unit.h"

void Unit::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

Unit::Unit(const std::sting& name, int hp, int dmg) {
    ensureIsAlive();
    this->damage = dmg;
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this>name = name;
}