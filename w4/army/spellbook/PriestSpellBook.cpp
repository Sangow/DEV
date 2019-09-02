#include "PriestSpellBook.h"

PriestSpellBook::PriestSpellBook(MagicState* mState) : SpellBook(mState) {
    this->spellList["Fireball"] = new Fireball(mState);
    this->spellList["Heal"] = new Heal(mState);

    this->currentSpell = spellList["Fireball"];
};

PriestSpellBook::~PriestSpellBook() {};