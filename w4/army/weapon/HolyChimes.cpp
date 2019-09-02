#include "HolyChimes.h"

HolyChimes::HolyChimes(Unit* owner) : Weapon("HolyChimes", owner) {
    this->dmg = this->owner->getStrength() * this->owner->getAgility() * 20;
};

HolyChimes::~HolyChimes() {};

void HolyChimes::attack(Unit* enemy) {
    std::cout << owner->getCharName() << " attacks " << enemy->getCharName() << std::endl;

    if ( enemy->getState().isUndead ) {
        enemy->takePhysDamage(this->dmg * 2);
        return;
    }
    enemy->counterAttack(this->owner);
};

void HolyChimes::counterAttack(Unit* enemy) {
    std::cout << owner->getCharName() << " counterAttacks " << enemy->getCharName() << std::endl;
    if ( enemy->getState().isUndead ) {
        enemy->takePhysDamage(this->dmg);
        return;
    }
    enemy->takePhysDamage(this->dmg / 2);
};