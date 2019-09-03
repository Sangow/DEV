#include "Dagger.h"

Dagger::Dagger(Unit* owner) : Weapon("Dagger", owner) {
    this->dmg = this->owner->getAgility() * 15;
};

Dagger::~Dagger() {};

void Dagger::attack(Unit* enemy) {
    std::cout << owner->getCharName() << " attacks " << enemy->getCharName() << std::endl;
    enemy->takePhysDamage(this->dmg);
};