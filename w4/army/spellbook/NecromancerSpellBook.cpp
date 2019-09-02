#include "NecromancerSpellBook.h"

NecromancerSpellBook::NecromancerSpellBook(MagicState* mState) : SpellBook(mState) {
    this->spellList["Fireball"] = new Fireball(mState);

    this->currentSpell = spellList["Fireball"];
};

NecromancerSpellBook::~NecromancerSpellBook() {};