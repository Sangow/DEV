#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "SpellCaster.h"
#include "../state/WizardState.h"
#include "../state/WizardMState.h"
#include "../weapon/Staff.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const std::string& charName);
        ~Wizard();
};

#endif // WIZARD_H