#include "Wizard.h"

Wizard::Wizard(const std::string& charName) : SpellCaster(charName, "Wizard") {
    this->state = new WizardState();
    this->mState = new WizardMState();
    this->weapon = new Staff(this);
};

Wizard::~Wizard() {};