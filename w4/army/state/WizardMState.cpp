#include "WizardMState.h"

WizardMState::WizardMState() : MagicState(150, 1.5, 1) {
    this->spellBook= new WizardSpellBook(this);
};

WizardMState::~WizardMState() {};