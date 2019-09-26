#include "HealerMState.h"

HealerMState::HealerMState() : MagicState(200, 0.5, 1) {
    this->spellBook = new HealerSpellBook(this);
};

HealerMState::~HealerMState() {};