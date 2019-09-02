#ifndef HEALER_MSTATE_H
#define HEALER_MSTATE_H

#include <iostream>
#include "MagicState.h"
#include "../spellbook/HealerSpellBook.h"

class HealerMState : public MagicState {
    public:
        HealerMState();
        virtual ~HealerMState();
};

#endif // HEALER_MSTATE_H