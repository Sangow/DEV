#include "UnitState.h"

UnitState::UnitState(float hp) : State(hp) {
    this->isVampire = false;
    this->isUndead = false;
    this->isWerewolf = false;
};

UnitState::~UnitState() {};