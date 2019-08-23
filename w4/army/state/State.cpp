#include "State.h"

void State::ensureIsAlive() {
    if ( this->hp == 0 ) {
        throw OutOfHPException();
    }
};

State::State(float hp, float dmg) : hp(hp), hpLimit(hp), dmg(dmg) {};

State::~State() {};

float State::getHP() const {
    return this->hp;
};

float State::getHPLimit() const {
    return this->hpLimit;
};

float State::getDMG() const {
    return this->dmg;
};

void State::takePhysDamage(float physDmg) {
    this->ensureIsAlive();

    if ( this->hp < dmg ) {
        this->hp = 0;
        return;
    }
    this->hp -= dmg;
};

void State::takeMagicDamage(float magicDmg) {
    this->takePhysDamage();
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
    out << "hp: (" << state.getHP() << "/" << state.getHPLimit() << "), ";
    out << "dmg: " << state.getDMG() << "]";

    return out;
};