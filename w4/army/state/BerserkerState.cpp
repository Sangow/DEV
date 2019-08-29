#include "BerserkerState.h"

BerserkerState::BerserkerState(float hp) : UnitState(hp) {
    this->strength = 1.5;
    this->agility = 0.5;
};

BerserkerState::~BerserkerState() {};

void BerserkerState::takeMagicDamage(float magicDmg) {
    std::cout << "Berserker cannot takeMagicDamage()!" << std::endl;
};