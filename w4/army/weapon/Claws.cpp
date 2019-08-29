#include "Claws.h"

Claws::Claws(Unit* owner) : Weapon("Claws", 10, owner), infectionChance(1) {};

Claws::~Claws() {};

void Claws::infect(Unit* enemy) {
    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {
        enemy->changeState(new VampireState(enemy->getHP(), enemy->getHPLimit()));
        enemy->changeWeapon(new Claws(enemy));
        std:: cout << enemy->getCharName() << " becomes Vampire!" << std::endl;
    }
    this->infectionChance += 1;
}

void Claws::attack(Unit* enemy) {
    enemy->takePhysDamage(this->dmg);
    owner->increaseHP(this->dmg / 10);

    this->infect(enemy);
};