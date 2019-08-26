#ifndef WEREWOLF_ABILITY_H
#define WEREWOLF_ABILITY_H

#include <iostream>
#include "ClassAbility.h"

class WerewolfAbility {
    public:
        WerewolfAbility(Unit* unit);
        virtual ~WerewolfAbility();

        virtual void ability() = 0;
}

#endif // CLASS_ABILITY_H