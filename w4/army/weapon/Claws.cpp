#include "Claws.h"

Claws::Claws(Unit* owner) : Weapon("Claws", 10, owner), infectionChance(1) {};

Claws::~Claws() {};

void Claws::action(Unit* enemy, float dmg) {
    enemy->takePhysDamage(dmg);
    owner->increaseHP(dmg / 10);

    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {
        enemy->changeState(new VampireState(enemy->getHP(), enemy->getHPLimit()));
        enemy->changeWeapon(new Claws(enemy));
        std:: cout << enemy->getCharName() << " becomes Vampire!" << std::endl;
    }
};