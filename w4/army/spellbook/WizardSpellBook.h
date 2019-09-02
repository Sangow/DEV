#ifndef WIZARD_SPELLBOOK_H
#define WIZARD_SPELLBOOK_H

#include <iostream>
#include "SpellBook.h"
#include "../spell/Fireball.h"
#include "../spell/Heal.h"

class WizardSpellBook : public SpellBook {
    public:
        WizardSpellBook(MagicState* mState);
        ~WizardSpellBook();
};

#endif // WIZARD_SPELLBOOK_H