#include "Wizard.h"

Wizard::Wizard(const char* charName) : SpellCaster(charName, "Wizard") {
    this->state = new WizardState();
    this->mState = new WizardMState();
    this->weapon = new Staff(this);
};

Wizard::~Wizard() {};

