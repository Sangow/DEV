#include "UnitState.h"

UnitState::UnitState(float hp) : State(hp) {
    isVampire = false;
    isUndead = false;
    isWerewolf = false;
};

UnitState::~UnitState() {};