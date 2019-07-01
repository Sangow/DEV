#include <iostream>
#include "Unit.h"

void Unit::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw UnitIsDead();
    }
}

Unit::Unit(const std::string& name, int hp, int dmg) {
    this->damage = dmg;
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this->name = name;
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

const std::string& Unit::getName() const {
    return this->name;
}

void Unit::addHitPoints(int hp) {
    this->ensureIsAlive();
    std::cout << this->name << " restored health!" << "\n" << std::endl;
    
    if( hp > this->hitPointsLimit - this->hitPoints ) {
        this->hitPoints = this->hitPointsLimit;
        return;
    }
    this->hitPoints += hp;
}

void Unit::takeDamage(int dmg) {
    this->ensureIsAlive();

    if ( dmg >= this->hitPoints ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= dmg;
}

void Unit::attack(Unit& enemy) {
    enemy.takeDamage(this->damage);
    std::cout << this->name << " attacked " << enemy.name << "\n" << std::endl;

    enemy.counterAttack(*this);
}

void Unit::counterAttack(Unit& enemy) {
   enemy.takeDamage(this->damage / 2);
   std::cout << this->name << " counterattacked " << enemy.name << "\n" << std::endl;
}

 std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    if ( unit.getHitPoints() == 0 ) {
        return out << "Unit '" << unit.getName() << "' is dead!"; 
    }
    out << "Unit: " << unit.getName() << "\n";
    out << "Health: " << unit.getHitPoints() << "/" << unit.getHitPointsLimit() << "HP\n";
    out << "Damage: " << unit.getDamage() << "dmg\n";
    return out;
 }