#ifndef NECROMANCER_STATE_H
#define NECROMANCER_STATE_H

#include <iostream>
#include "MagicState.h"

class NecromancerState : public MagicState {
    public:
        NecromancerState(float hp, float mana, float intellect, float faith);
        ~NecromancerState();
};

#endif // NECROMANCER_STATE_H