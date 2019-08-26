#include "UnitState.h"

UnitState::UnitState(float hp) : State(hp) {
    isVampire = false;
    isWerewolf = false;
};

UnitState::~UnitState() {};