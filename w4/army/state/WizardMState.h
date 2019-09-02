#ifndef WIZARD_MSTATE_H
#define WIZARD_MSTATE_H

#include <iostream>
#include "MagicState.h"
#include "../spellbook/WizardSpellBook.h"

class WizardMState : public MagicState {
    public:
        WizardMState();
        virtual ~WizardMState();
};

#endif // WIZARD_MSTATE_H