#include "Unit.h"

Unit::Unit(const char* charName, const char* charClass) : charClass(charClass), charName(charName) {};

Unit::~Unit() {
    delete this->state;
    delete this->weapon;
};

float Unit::getHP() const {
    return this->state->getHP();
};

float Unit::getHPLimit() const {
    return this->state->getHPLimit();
};

float Unit::getDMG() const {
    return this->weapon->getDMG();
};

const char* Unit::getCharClass() const {
    return this->charClass;
};

const char* Unit::getCharName() const {
    return this->charName;
};

State& Unit::getState() const {
    return *(this->state);
};

Weapon& Unit::getWeapon() const {
    return *(this->weapon);
};

void Unit::takePhysDamage(float physDmg) {
    this->state->takePhysDamage(physDmg);
};

void Unit::takeMagicDamage(float magicDmg) {
    this->state->takeMagicDamage(magicDmg);
};

void Unit::increaseHP(float extraHP) {
    this->state->increaseHP(extraHP);
};

void Unit::changeState(State* newState) {
    this->state = newState;
};

void Unit::changeWeapon(Weapon* newWeapon) {
    this->weapon = newWeapon;
};

bool Unit::readyToBeInfected() {
    this->state->readyToBeInfected();
};

void Unit::attack(Unit* enemy) {
    try {
        this->weapon->action(enemy, this->getDMG());
        enemy->counterAttack(this);
    } catch (OutOfHPException) {
        std::cout << "Unit \"" << enemy->getCharName() << "\" is DEAD!!!" << std::endl; 
    }
};

void Unit::counterAttack(Unit* enemy) {
    this->weapon->action(enemy, this->getDMG() / 2);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getCharClass() << ": " << unit.getCharName();
    out << unit.getState();
    out << unit.getWeapon();

    return out;
};