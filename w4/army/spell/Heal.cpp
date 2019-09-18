#include "Heal.h"

Heal::Heal(MagicState* mState) : Spell(mState, "Heal", 20, 20) {};

Heal::~Heal() {};

void Heal::action(Unit* enemy) {
    this->mState->spendMana(this->cost);
    enemy->increaseHP(this->points * this->mState->getFaith());
};