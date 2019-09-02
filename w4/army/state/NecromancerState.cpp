#include "NecromancerState.h"

NecromancerState::NecromancerState() : UndeadState(80) {
    this->isVampire = false;
    this->isWerewolf = false;

    this->strength = 0.2;
    this->agility = 0.1;
};

NecromancerState::~NecromancerState() {};