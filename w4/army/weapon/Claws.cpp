#include "Claws.h"

Claws::Claws(Unit* owner) : Weapon("Claws", owner) {
    this->dmg = this->owner->getAgility() * 10;
};

Claws::~Claws() {};

void Claws::attack(Unit* enemy) {
    enemy->takePhysDamage(this->dmg);
    owner->increaseHP((enemy->getHP() + this->dmg) / 10);

    enemy->counterAttack(owner);
};

void Claws::counterAttack(Unit* enemy) {
    enemy->takePhysDamage(this->dmg / 2);
    owner->increaseHP((enemy->getHP() + this->dmg) / 10);
}