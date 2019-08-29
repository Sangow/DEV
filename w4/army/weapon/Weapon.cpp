#include "Weapon.h"

Weapon::Weapon(const char* weaponName, float dmg, Unit* owner) 
    : dmg(dmg), weaponName(weaponName), owner(owner) {};

Weapon::~Weapon() {
    delete weaponName;
    delete owner;
};

const char* Weapon::getWeaponName() const {
    return this->weaponName;
};

float Weapon::getDMG() const {
    return this->dmg;
};

void Weapon::attack(Unit* enemy) {
    enemy->takePhysDamage(this->dmg);
    enemy->counterAttack(this->owner);
}

void Weapon::counterAttack(Unit* enemy) {
    enemy->takePhysDamage(this->dmg / 2);
}

std::ostream& operator<<(std::ostream& out, const Weapon& weapon) {
    out << "Weapon: " << weapon.getWeaponName();
    out << " [dmg: " << weapon.getDMG();
    out << "]";

    return out;
};