#include "State.h"

void State::ensureIsAlive() {
    if ( this->hp == 0 ) {
        throw OutOfHPException();
    }
};

State::State(float hp) : hp(hp), hpLimit(hp) {};

// State::State(float hp, float hpLimit) : hp(hp), hpLimit(hpLimit) {};

State::~State() {};

float State::getHP() const {
    return this->hp;
};

float State::getHPLimit() const {
    return this->hpLimit;
};

float State::getStrength() const {
    return this->strength;
};

float State::getAgility() const {
    return this->agility;
};

bool State::readyToBeInfected() {
    return !this->isVampire && !this->isWerewolf;
};

void State::takePhysDamage(float physDmg) {
    this->ensureIsAlive();

    if ( this->hp < physDmg ) {
        this->hp = 0;
        return;
    }
    this->hp -= physDmg;
};

void State::takeMagicDamage(float magicDmg) {
    this->takePhysDamage(magicDmg);
};

void State::increaseHP(float hp) {
    this->ensureIsAlive();

    int totalHP = this->hp + hp;

    if ( totalHP > this->hpLimit ) {
        this->hp = this->hpLimit;
        return;
    }
    this->hp = totalHP;
};

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << " [";
    out << "hp: " << state.getHP() << "/" << state.getHPLimit();
    out << "]" << std::endl;

    return out;
};