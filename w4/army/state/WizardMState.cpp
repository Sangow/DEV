#include "WizardMState.h"

WizardMState::WizardMState() : MagicState(150, 1, 0.5) {
    this->spellBook= new WizardSpellBook(this);
};

WizardMState::~WizardMState() {};