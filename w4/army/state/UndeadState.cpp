#include "UndeadState.h"

UndeadState::UndeadState(float hp) : State(hp) {
    this->isUndead = true;
};

UndeadState::~UndeadState() {};