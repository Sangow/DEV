#include "Attack.h"

Weapon::Weapon(Unit* owner, float dmg, const char* weaponName) 
    : owner(owner), dmg(dmg), weaponName(weaponName) {};

Weapon::~Weapon() {
    delete owner
    delete weaponName;
};

void Weapon::action(Unit* enemy) {
    enemy->takeDamage
};
// void Attack::attack(Unit* enemy) {
//     enemy->takeDamage(this->instance->getDMG());
//     enemy->counterAttack(this->instance);
// };

// void Attack::counterAttack(Unit* enemy) {
//     enemy->takeDamage(this->instance->getDMG() / 2);
// };