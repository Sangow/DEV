#ifndef WARLOCK_MSTATE_H
#define WARLOCK_MSTATE_H

#include <iostream>
#include "MagicState.h"
#include "../spellbook/WarlockSpellBook.h"

class WarlockMState : public MagicState {
    public:
        WarlockMState();
        virtual ~WarlockMState();
};

#endif // WARLOCK_MSTATE_H