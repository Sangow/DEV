#include "VampireState.h"

VampireState::VampireState() : UndeadState(90) {
    this->isVampire = true;
    this->isWerewolf = false;

    this->strength = 0.5;
    this->agility = 1.2;
};

VampireState::~VampireState() {};