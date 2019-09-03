#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Unit.h"
#include "../state/RogueState.h"
#include "../weapon/Dagger.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& charName);
        ~Rogue();
};

#endif // ROGUE_H