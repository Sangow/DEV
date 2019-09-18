#include "WerewolfState.h"

WerewolfState::WerewolfState(double hp) : State(hp) {
    this->isVampire = false;
    this->isUndead = false;
    this->isWerewolf = true;

    this->strength = 1.25;
    this->agility = 0.75;
};

WerewolfState::~WerewolfState() {};