#include "State.h"

State::State(double hp) : hp(hp), hpLimit(hp) {};

State::~State() {};

double State::getHP() const {
    return this->hp;
};

double State::getHPLimit() const {
    return this->hpLimit;
};

double State::getStrength() const {
    return this->strength;
};

double State::getAgility() const {
    return this->agility;
};

bool State::readyToBeInfected() {
    return !this->isVampire && !this->isWerewolf;
};

void State::takePhysDamage(double physDmg) {
    if ( this->hp < physDmg ) {
        this->hp = 0;
        return;
    }
    this->hp -= physDmg;
};

void State::takeMagicDamage(double magicDmg) {
    this->takePhysDamage(magicDmg);
};

void State::increaseHP(double hp) {
    int totalHP = this->hp + hp;

    if ( totalHP > this->hpLimit ) {
        this->hp = this->hpLimit;
        return;
    }
    this->hp = totalHP;
};

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << "[";
    out << "hp: " << state.getHP() << "/" << state.getHPLimit();
    out << "]";

    return out;
};