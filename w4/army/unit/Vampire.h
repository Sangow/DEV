#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include <string>
#include "Unit.h"
#include "../state/VampireState.h"
#include "../weapon/Claws.h"
#include "../classAbility/VampireAbility.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& charName);
        ~Vampire();
};

#endif // VAMPIRE_H