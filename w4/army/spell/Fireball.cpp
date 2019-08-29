#include "Fireball.h"

Fireball::Fireball() : Spell("Fireball", 30, 30) {};

Fireball::~Fireball() {};

void Fireball::action(Unit* enemy) {
    enemy->takeMagicDamage(this->points);
};