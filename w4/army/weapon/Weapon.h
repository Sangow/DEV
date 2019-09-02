#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "../unit/Unit.h"
#include "../exceptions/Exceptions.h"

class Unit;

class Weapon {
    protected:
        Unit* owner;
        const std::string weaponName;
        float dmg;

    public:
        Weapon(const std::string& weaponName, Unit* owner);
        virtual ~Weapon();

        const std::string& getWeaponName() const;
        float getDMG() const;

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Weapon& weapon);

#endif // ATACK_H