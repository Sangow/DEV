#include "NecromancerMState.h"

NecromancerMState::NecromancerMState() : MagicState(120, 1.5, 0.5) {
    this->spellBook = new NecromancerSpellBook(this);
};

NecromancerMState::~NecromancerMState() {};