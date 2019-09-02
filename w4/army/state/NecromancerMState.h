#ifndef NECROMANCER_MSTATE_H
#define NECROMANCER_MSTATE_H

#include <iostream>
#include "MagicState.h"
#include "../spellbook/NecromancerSpellBook.h"

class NecromancerMState : public MagicState {
    public:
        NecromancerMState();
        ~NecromancerMState();
};

#endif // NECROMANCER_MSTATE_H