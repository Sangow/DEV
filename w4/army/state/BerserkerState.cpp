#include "BerserkerState.h"

BerserkerState::BerserkerState() : HumanState(150, 1.5, 0.5) {};

BerserkerState::~BerserkerState() {};

void BerserkerState::takeMagicDamage(double magicDmg) {
    std::cout << "Berserker cannot takeMagicDamage()!" << std::endl;
};