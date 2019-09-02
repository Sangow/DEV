#ifndef PRIEST_MSTATE_H
#define PRIEST_MSTATE_H

#include <iostream>
#include "MagicState.h"
#include "../spellbook/PriestSpellBook.h"

class PriestMState : public MagicState {
    public:
        PriestMState();
        virtual ~PriestMState();
};

#endif // PRIEST_MSTATE_H