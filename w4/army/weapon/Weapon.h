#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "../unit/Unit.h"

class Unit;

class Weapon {
    protected:
        const char* weaponName;
        float dmg;
        Unit* owner;

    public:
        Weapon(Unit* owner, float dmg, const char* weaponName);
        virtual ~Weapon();

        virtual void action(Unit* enemy);
        // virtual void attack(Unit* enemy);
        // virtual void counterAttack(Unit* enemy);
};

#endif // ATACK_H