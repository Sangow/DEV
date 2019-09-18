#include "Fireball.h"

Fireball::Fireball(MagicState* mState) : Spell(mState, "Fireball", 30, 30) {};

Fireball::~Fireball() {};

void Fireball::action(Unit* enemy) {
    this->mState->spendMana(this->cost);
    enemy->takeMagicDamage(this->points * this->mState->getIntellect());
};