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

void Weapon::action(Unit* enemy, float dmg) {
        enemy->takePhysDamage(dmg);
        // std::cout << enemy->getCharName() << " is DEAD!" << std::endl;
};

std::ostream& operator<<(std::ostream& out, const Weapon& weapon) {
    out << "Weapon: " << weapon.getWeaponName();
    out << " [dmg: " << weapon.getDMG();
    out << "]";

    return out;
};