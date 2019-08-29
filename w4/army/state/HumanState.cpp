#include "HumanState.h"

HumanState::HumanState(float hp, float strength, float agility) : State(hp) {
    isVampire = false;
    isUndead = false;
    isWerewolf = false;

    this->strength = strength;
    this->agility = agility;
};

HumanState::~HumanState() {};