#include "WarlockMState.h"

WarlockMState::WarlockMState() : MagicState(125, 1, 1) {
    this->spellBook = new WarlockSpellBook(this);
};

WarlockMState::~WarlockMState() {};