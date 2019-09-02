// Berserker weapon
#ifndef TWO_HANDED_SWORD_H
#define TWO_HANDED_SWORD_H

#include <iostream>
#include "Weapon.h"

class TwoHandedSword : public Weapon {
    public:
        TwoHandedSword(Unit* owner);
        ~TwoHandedSword();
};

#endif // TWO_HANDED_SWORD_H