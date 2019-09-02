#ifndef PRIEST_SPELLBOOK_H
#define PRIEST_SPELLBOOK_H

#include <iostream>
#include "SpellBook.h"
#include "../spell/Fireball.h"
#include "../spell/Heal.h"

class PriestSpellBook : public SpellBook {
    public:
        PriestSpellBook(MagicState* mState);
        ~PriestSpellBook();
};

#endif // PRIEST_SPELLBOOK_H