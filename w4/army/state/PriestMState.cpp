#include "PriestMState.h"

PriestMState::PriestMState() : MagicState(150, 1, 1.5) {
    this->spellBook = new PriestSpellBook(this);
};

PriestMState::~PriestMState() {};