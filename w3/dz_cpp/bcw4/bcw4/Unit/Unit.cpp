#include <iostream>
#include "Unit.h"

void Unit::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

Unit::Unit(const std::sting& name, int hp, int dmg) {
    this->ensureIsAlive();
    this->damage = dmg;
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this>name = name;
}

Unit::~Unit() {}

int Unit::getDamage() const {
    return this->damage;
}

int Unit::getHitPoints() const {
    return this->hitPoints;
}

int Unit::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

const std::sting& Unit::getName() const {
    return this->name;
}

void Unit::addHitPoints(int hp) {
    this->ensureIsAlive();

    if( hp > this->hitPointsLimit - this->hitPoints ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints += hp;
}

void Unit::takeDamage(int dmg) {
    this->ensureIsAlive();

    if ( dmg > this->hitPoints ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= dmg;
}

void Unit::attack(Unit& enemy) {
    // enemy.ensureIsAlive(); ??
    enemy.takeDamage(this->damage);
    enemy.ensureIsAlive();

    enemy.counterAttack(*this);
}
 void Unit::counterAttack(Unit& enemy) {

 }