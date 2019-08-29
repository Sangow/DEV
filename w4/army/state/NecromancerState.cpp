#include "NecromancerState.h"

NecromancerState::NecromancerState(float hp, float mana, float intellect, float faith) : MagicState(hp, mana, intellect, faith) {
    this->isUndead = true;
};

NecromancerState::~NecromancerState() {};