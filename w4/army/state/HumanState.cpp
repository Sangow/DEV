#include "HumanState.h"

HumanState::HumanState(double hp, double strength, double agility) : State(hp) {
    isVampire = false;
    isUndead = false;
    isWerewolf = false;

    this->strength = strength;
    this->agility = agility;
};

HumanState::~HumanState() {};