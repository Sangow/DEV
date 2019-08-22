#include "Unit.h"

Unit::Unit(float hp, float dmg, const char* title) 
    : state(new State(hp, dmg, title)) {
    this->_attack = new Attack(this);
};

Unit::~Unit() {
    delete this->state;
    delete this->_attack;
};

float Unit::getHP() const {
    return this->state->getHP();
};

float Unit::getHPLimit() const {
    return this->state->getHPLimit();
};

float Unit::getDMG() const {
    return this->state->getDMG();
};

const char* Unit::getTitle() const {
    return this->state->getTitle();
};

State& Unit::getState() const {
    return *(this->state);
};

void Unit::takeDamage(float dmg) {
    this->state->takeDamage(dmg);
};

void Unit::increaseHP(float hp) {
    this->state->increaseHP(hp);
};

void Unit::attack(Unit* enemy) {
    this->_attack->attack(enemy);
};

void Unit::counterAttack(Unit* enemy) {
    this->_attack->counterAttack(enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getState();

    return out;
};