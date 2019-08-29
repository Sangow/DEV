#include "Claws.h"

Claws::Claws(Unit* owner) : Weapon("Claws", owner), infectionChance(1) {
    this->dmg = this->owner->getAgility() * 10;
};

Claws::~Claws() {};

void Claws::infect(Unit* enemy) {
    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {
        float enemyHP = enemy->getHP();

        enemy->changeState(new VampireState());
        enemy->takePhysDamage(this->owner->getHPLimit() - (enemyHP * this->owner->getHPLimit()) / 100);
        enemy->changeWeapon(new Claws(enemy));
        std:: cout << enemy->getCharName() << " becomes Vampire!" << std::endl;
    }
    this->infectionChance += 1;
}

void Claws::attack(Unit* enemy) {
    enemy->takePhysDamage(this->dmg);
    owner->increaseHP((enemy->getHP() + this->dmg) / 10);

    enemy->counterAttack(owner);

    this->infect(enemy);
};