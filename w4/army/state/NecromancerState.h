#ifndef NECROMANCER_STATE_H
#define NECROMANCER_STATE_H

#include <iostream>
#include "MagicState.h"

class NecromancerState : public UndeadState {
    public:
        NecromancerState();
        ~NecromancerState();
};

#endif // NECROMANCER_STATE_H