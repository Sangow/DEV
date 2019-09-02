#include "WarlockSpellBook.h"

WarlockSpellBook::WarlockSpellBook(MagicState* mState) : SpellBook(mState) {
    this->spellList["Fireball"] = new Fireball(mState);
    this->spellList["Heal"] = new Heal(mState);

    this->currentSpell = spellList["Fireball"];
};

WarlockSpellBook::~WarlockSpellBook() {};