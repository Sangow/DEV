#ifndef STAFF_H
#define STAFF_H

// Spellcasters weapon

#include <iostream>
#include "Weapon.h"
#include "../spell/Spell.h"

class Staff : public Weapon {
    public:
        Staff(Unit* owner);
        ~Staff();

        void cast(const char* spellName, Unit* enemy);
};


#endif // STAFF_H