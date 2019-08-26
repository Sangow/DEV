#include "WolfState.h"

WolfState::WolfState(float hp, float hpLimit) : WerewolfState(hp, hpLimit) {
    this->isWolf = true;
};

WolfState::~WolfState() {};

void WolfState::takeMagicDamage(float magicDmg) {
    this->takePhysDamage(magicDmg * 2);
};