#ifndef NECROMANCER_SPELLBOOK_H
#define NECROMANCER_SPELLBOOK_H

#include <iostream>
#include "SpellBook.h"
#include "../spell/Fireball.h"

class NecromancerSpellBook : public SpellBook {
    public:
        NecromancerSpellBook(MagicState* mState);
        ~NecromancerSpellBook();
};

#endif // NECROMANCER_SPELLBOOK_H`