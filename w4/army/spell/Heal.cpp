#include "Heal.h"

Heal::Heal() : Spell("Heal", 20, 20) {};

Heal::~Heal() {};

void Heal::action(Unit* enemy) {
    enemy->increaseHP(this->points);
};