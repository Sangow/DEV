#include "WolfAbility.h"

WolfAbility::WolfAbility(Unit* owner) : ClassAbility(owner), infectionChance(1) {
    this->byteDamage = owner->getAgility() * 5.0;
};

WolfAbility::~WolfAbility() {};

void WolfAbility::useAbility() {
    this->transform();
}

void WolfAbility::useAbility(Unit* enemy) {
    this->bite(enemy);
};

void WolfAbility::transform() {
    double oldHP = owner->getHP();

    owner->changeState(new WerewolfState(), "Werewolf");
    owner->takePhysDamage(owner->getHPLimit() - (oldHP / 2));
    owner->changeWeapon(new Mace(owner));
    owner->changeAbility(new WerewolfAbility(owner));
    std::cout << owner->getCharName() << " transformed in Werewolf." << std::endl;
};

void WolfAbility::bite(Unit* enemy) {
    try {
        enemy->takePhysDamage(this->byteDamage);
        std::cout << enemy->getCharName() << " was bitten by " << owner->getCharName() << "." << std::endl;
    } catch (OutOfHPException e) {
        std::cout << owner->getCharName() << " cannot bite " << enemy->getCharName() << ": " << e.message << std::endl;
        return;
    }

    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {

        double oldHP = enemy->getHP();
        double oldHPLimit = enemy->getHPLimit();

        enemy->changeState(new WerewolfState(), "Werewolf");
        enemy->takePhysDamage(enemy->getHPLimit() - (oldHP * enemy->getHPLimit()) / oldHPLimit);
        enemy->changeWeapon(new Mace(enemy));
        enemy->changeAbility(new WerewolfAbility(enemy));
        std::cout << enemy->getCharName() << " was infected by " << owner->getCharName() << " and turned into Werewolf." << std::endl;
    }
    this->infectionChance += 1;
};