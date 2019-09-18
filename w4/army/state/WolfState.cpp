#include "WolfState.h"

WolfState::WolfState() : WerewolfState(200) {
    // this->isWolf = true;
    this->strength = 2.5;
    this->agility = 1.5;
};

WolfState::~WolfState() {};

void WolfState::takeMagicDamage(double magicDmg) {
    this->takePhysDamage(magicDmg * 2);
};