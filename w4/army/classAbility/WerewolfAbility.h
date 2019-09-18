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

        virtual void useAbility() override;
        virtual void useAbility(Unit* enemy) override;

        void transform();
};

#endif // WEREWOLF_ABILITY