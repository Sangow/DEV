#ifndef VAMPIRE_ABILITY_H
#define VAMPIRE_ABILITY_H

#include <iostream>
#include "ClassAbility.h"
#include "../state/VampireState.h"
#include "../weapon/Claws.h"

class VampireAbility : public ClassAbility {
    protected:
        int infectionChance;
    public:
        VampireAbility(Unit* owner);
        ~VampireAbility();

        virtual void useAbility();
        virtual void useAbility(Unit* enemy);

        void kiss(Unit* enemy);
};

#endif // VAMPIRE_ABILITY_H