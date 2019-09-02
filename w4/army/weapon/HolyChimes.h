// Priest weapon
#ifndef HOLY_CHIMES_H
#define HOLY_CHIMES_H

#include <iostream>
#include "Weapon.h"

class HolyChimes : public Weapon {
    public:
        HolyChimes(Unit* owner);
        ~HolyChimes();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // HOLY_CHIMES_H