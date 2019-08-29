#ifndef WEREWOLF_STATE_H
#define WEREWOLF_STATE_H

#include <iostream>
#include "State.h"

class WerewolfState : public State {
    public:
        WerewolfState(float hp = 100);
        virtual ~WerewolfState();
};

#endif // WEREWOLF_STATE_H