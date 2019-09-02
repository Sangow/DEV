#ifndef WARLOCK_SPELLBOOK_H
#define WARLOCK_SPELLBOOK_H

#include <iostream>
#include "SpellBook.h"
#include "../spell/Fireball.h"
#include "../spell/Heal.h"

class WarlockSpellBook : public SpellBook {
    public:
        WarlockSpellBook(MagicState* mState);
        ~WarlockSpellBook();
};

#endif // WARLOCK_SPELLBOOK_H