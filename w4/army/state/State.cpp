#include "State.h"

void State::ensureIsAlive() {
    if ( this->hp == 0 ) {
        throw OutOfHPException();
    }
};

State::State(float hp, float dmg, const char* title) : hp(hp), hpLimit(hp), 
                                                        dmg(dmg), title(title) {};

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

const char* State::getTitle() const {
    return this->title;
};

void State::takeDamage(float dmg) {
    this->ensureIsAlive();

    if ( this->hp < dmg ) {
        this->hp = 0;
        return;
    }
    this->hp -= dmg;
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

std::ostream& operator<<(std::ostream& out, const State* state) {
    out << state->getTitle() << " [";
    out << "hp: (" << state->getHP() << "/" << state->getHPLimit() << "), ";
    out << "dmg: " << state->getDMG() << "]";

    return out;
};