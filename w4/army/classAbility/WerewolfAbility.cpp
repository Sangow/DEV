#include "WerewolfAbility.h"

WerewolfAbility::WerewolfAbility(Unit* owner) : ClassAbility(owner) {};

WerewolfAbility::~WerewolfAbility() {};

void WerewolfAbility::useAbility() {
    this->transform();
};

void WerewolfAbility::useAbility(Unit* enemy) {
    std::cout << owner->getCharName() << ", nothing to do with this enemy unit!" << std::endl;
};

void WerewolfAbility::transform() {
    float oldHP = owner->getHP();
    float oldHPLimit = owner->getHPLimit();

    owner->changeState(new WolfState(), "Wolf");
    owner->takePhysDamage(owner->getHPLimit() - (oldHP * owner->getHPLimit()) / oldHPLimit);
    owner->changeWeapon(new Fangs(owner));
    owner->changeAbility(new WolfAbility(owner));
    std::cout << owner->getCharName() << " transformed in Wolf." << std::endl;
};