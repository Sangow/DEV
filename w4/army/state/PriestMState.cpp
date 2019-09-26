#include "PriestMState.h"

PriestMState::PriestMState() : MagicState(150, 0.5, 1) {
    this->spellBook = new PriestSpellBook(this);
};

PriestMState::~PriestMState() {};