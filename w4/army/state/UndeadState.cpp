#include "UndeadState.h"

UndeadState::UndeadState(double hp) : State(hp) {
    this->isUndead = true;
};

UndeadState::~UndeadState() {};