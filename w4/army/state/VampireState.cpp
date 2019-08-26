#include "VampireState.h"

VampireState::VampireState(float hp) : State(hp) {
    this->isVampire = true;
    this->isWerewolf = false;
};

VampireState::VampireState(float hp, float hpLimit) : State(hp, hpLimit) {
    this->isVampire = true;
    this->isWerewolf = false;
    // unit->changeWeapon(new Claws(unit));
}

VampireState::~VampireState() {};

