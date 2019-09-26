#include "WerewolfAbility.h"

WerewolfAbility::WerewolfAbility(Unit* owner) : ClassAbility(owner) {};

WerewolfAbility::~WerewolfAbility() {};

void WerewolfAbility::useAbility() {
    try {
        owner->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << owner->getCharName() << " cannot tranform: " << owner->getCharName() << e.message << std::endl;
        return;
    }
    this->transform();
};

void WerewolfAbility::useAbility(Unit* enemy) {
    std::cout << owner->getCharName() << ", nothing to do with this enemy unit!" << std::endl;
};

void WerewolfAbility::transform() {
    double oldHP = owner->getHP();
    double oldHPLimit = owner->getHPLimit();

    owner->changeState(new WolfState(), "Wolf");
    owner->takePhysDamage(owner->getHPLimit() - (oldHP * owner->getHPLimit()) / oldHPLimit);
    owner->changeWeapon(new Fangs(owner));
    owner->changeAbility(new WolfAbility(owner));
    std::cout << owner->getCharName() << " transformed in Wolf." << std::endl;
};