#ifndef WEREWOLF_ABILITY
#define WEREWOLF_ABILITY

#include <iostream>
#include "ClassAbility.h"
#include "../state/WolfState.h"
#include "../weapon/Fangs.h"
#include "WolfAbility.h"

class WerewolfAbility : public ClassAbility {
    public:
        WerewolfAbility(Unit* owner);
        virtual ~WerewolfAbility();

        virtual void useAbility();
        virtual void useAbility(Unit* enemy);

        void transform();
        void bite();
};

#endif // WEREWOLF_ABILITY