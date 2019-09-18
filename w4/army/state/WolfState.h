#ifndef WOLF_STATE_H
#define WOLF_STATE_H

#include <iostream>
#include "WerewolfState.h"
#include "../weapon/Fangs.h"

class WolfState : public WerewolfState {
    public:
        WolfState();
        virtual ~WolfState();

        virtual void takeMagicDamage(double magicDmg);
};

#endif // WEREWOLF_STATE_H