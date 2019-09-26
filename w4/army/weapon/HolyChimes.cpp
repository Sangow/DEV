#include "HolyChimes.h"

HolyChimes::HolyChimes(Unit* owner) : Weapon("HolyChimes", owner) {
    this->dmg = this->owner->getStrength() * this->owner->getAgility() * 10;
};

HolyChimes::~HolyChimes() {};

void HolyChimes::attack(Unit* enemy) {
    if ( enemy->getState().isUndead ) {
        enemy->takePhysDamage(this->dmg * 2);
    } else {
        enemy->takePhysDamage(this->dmg);
    }

    enemy->counterAttack(this->owner);
};

void HolyChimes::counterAttack(Unit* enemy) {
    if ( enemy->getState().isUndead ) {
        enemy->takePhysDamage(this->dmg);
        return;
    }
    enemy->takePhysDamage(this->dmg / 2);
};