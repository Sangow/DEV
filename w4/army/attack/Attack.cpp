#include "Attack.h"

Attack::Attack(Unit* instance) : instance(instance) {};

Attack::~Attack() {
    delete instance;
};

void Attack::attack(Unit* enemy) {
    enemy->takeDamage(this->instance->getDMG());
    enemy->counterAttack(this->instance);
};

void Attack::counterAttack(Unit* enemy) {
    enemy->takeDamage(this->instance->getDMG() / 2);
};