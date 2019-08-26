#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "../unit/Unit.h"
#include "../exceptions/Exceptions.h"

class Unit;

class Weapon {
    protected:
        Unit* owner;
        const char* weaponName;
        float dmg;

    public:
        Weapon(const char* weaponName, float dmg, Unit* owner);
        virtual ~Weapon();

        const char* getWeaponName() const;
        float getDMG() const;

        virtual void action(Unit* enemy, float dmg);
};

std::ostream& operator<<(std::ostream& out, const Weapon& weapon);

#endif // ATACK_H