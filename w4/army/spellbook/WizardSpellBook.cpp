#include "WizardSpellBook.h"

WizardSpellBook::WizardSpellBook(MagicState* mState) : SpellBook(mState) {
    this->spellList["Fireball"] = new Fireball(mState);
    this->spellList["Heal"] = new Heal(mState);

    this->currentSpell = spellList["Fireball"];
};

WizardSpellBook::~WizardSpellBook() {};