#include "HealerSpellBook.h"

HealerSpellBook::HealerSpellBook(MagicState* mState) : SpellBook(mState) {
    this->spellList["Fireball"] = new Fireball(mState);
    this->spellList["Heal"] = new Heal(mState);

    this->currentSpell = spellList["Fireball"];
};

HealerSpellBook::~HealerSpellBook() {};