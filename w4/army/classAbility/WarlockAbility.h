#ifndef WARLOCK_ABILITY_H
#define WARLOCK_ABILITY_H

#include <iostream>
#include "ClassAbility.h"
#include "../unit/Demon.h"
#include "../unit/SpellCaster.h"

class Demon;

class WarlockAbility : public ClassAbility {
    protected:
        Demon* slave;
    public:
        WarlockAbility(Unit* owner);
        ~WarlockAbility();

        virtual void useAbility();
        virtual void useAbility(Unit* enemy);

        void summonSlave();
        // void freeSlave();
};

#endif // WARLOCK_ABILITY_H