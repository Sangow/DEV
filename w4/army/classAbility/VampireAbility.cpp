#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* owner) : ClassAbility(owner), infectionChance(1) {};

VampireAbility::~VampireAbility() {};

void VampireAbility::useAbility() {
    std::cout << owner->getCharName() << ", choose the enemy to kiss!!!" << std::endl;
};

void VampireAbility::useAbility(Unit* enemy) {
    this->kiss(enemy);
};

void VampireAbility::kiss(Unit* enemy) {
        std::cout << enemy->getCharName() << " was kissed by " << owner->getCharName() << "." << std::endl;
    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {
        float oldHP = enemy->getHP();
        float oldHPLimit = enemy->getHPLimit();

        enemy->changeState(new VampireState(), "Vampire");
        enemy->takePhysDamage(enemy->getHPLimit() - (oldHP * enemy->getHPLimit()) / oldHPLimit);
        enemy->changeWeapon(new Claws(enemy));
        enemy->changeAbility(new VampireAbility(enemy));
        std::cout << enemy->getCharName() << " was infected by " << owner->getCharName() << " and turned into Vampire." << std::endl;
    }
    this->infectionChance += 1;
};