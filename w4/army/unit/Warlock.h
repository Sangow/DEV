#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>
#include "Unit.h"
#include "../state/WarlockState.h"
#include "../state/WarlockMState.h"
#include "../classAbility/WarlockAbility.h"
#include "../weapon/Sickle.h"

class Warlock : public SpellCaster {
    public:
        Warlock(const char* charName);
        ~Warlock();
};

#endif // WARLOCK_H