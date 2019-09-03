#include "Weapon.h"

Weapon::Weapon(const std::string& weaponName, Unit* owner) 
    : weaponName(weaponName), owner(owner) {};

Weapon::~Weapon() {};

const std::string& Weapon::getWeaponName() const {
    return this->weaponName;
};

float Weapon::getDMG() const {
    return this->dmg;
};

void Weapon::attack(Unit* enemy) {
    std::cout << owner->getCharName() << " attacks " << enemy->getCharName() << std::endl;
    enemy->takePhysDamage(this->dmg);
    enemy->counterAttack(this->owner);
};

void Weapon::counterAttack(Unit* enemy) {
    std::cout << owner->getCharName() << " counterAttacks " << enemy->getCharName() << std::endl;
    enemy->takePhysDamage(this->dmg / 2);
};

std::ostream& operator<<(std::ostream& out, const Weapon& weapon) {
    out << "Weapon: " << weapon.getWeaponName();
    out << " [dmg: " << weapon.getDMG();
    out << "]";

    return out;
};