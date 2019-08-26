#include "WerewolfState.h"

WerewolfState::WerewolfState(float hp) : State(hp) {
    this->isVampire = false;
    this->isWerewolf = true;
    this->isWolf = false;
};

WerewolfState::WerewolfState(float hp, float hpLimit) : State(hp, hpLimit) {
    this->isWolf = false;
};

WerewolfState::~WerewolfState() {};