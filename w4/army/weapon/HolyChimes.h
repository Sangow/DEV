// Priest weapon
#ifndef HOLY_CHIMES_H
#define HOLY_CHIMES_H

#include <iostream>
#include "Weapon.h"

class HolyChimes : public Weapon {
    public:
        HolyChimes(Unit* owner);
        ~HolyChimes();

        virtual void attack(Unit* enemy) override;
        virtual void counterAttack(Unit* enemy) override;
};

#endif // HOLY_CHIMES_H