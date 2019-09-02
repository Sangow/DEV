#include "HealerMState.h"

HealerMState::HealerMState() : MagicState(200, 1, 1.5) {
    this->spellBook = new HealerSpellBook(this);
};

HealerMState::~HealerMState() {};