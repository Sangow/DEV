#ifndef HEALER_SPELLBOOK_H
#define HEALER_SPELLBOOK_H

#include <iostream>
#include "SpellBook.h"
#include "../spell/Fireball.h"
#include "../spell/Heal.h"

class HealerSpellBook : public SpellBook {
    public:
        HealerSpellBook(MagicState* mState);
        ~HealerSpellBook();
};

#endif // HEALER_SPELLBOOK_H