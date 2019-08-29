#include "Dagger.h"

Dagger::Dagger(Unit* owner) : Weapon("Dagger", 12, owner) {};

Dagger::~Dagger() {};

void Dagger::attack(Unit* enemy) {
    enemy->takePhysDamage(this->dmg);
};