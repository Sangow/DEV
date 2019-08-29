#include "NecromancerState.h"

NecromancerState::NecromancerState() : UndeadState(80) {
    this->isVampire = false;
    this->isWerewolf = false;

    this->strength = 0.5;
    this->agility = 1;
};

NecromancerState::~NecromancerState() {};