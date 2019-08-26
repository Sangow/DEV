#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Unit.h"
#include "../state/UnitState.h"
#include "../weapon/Dagger.h"

class Rogue : public Unit {
    public:
        Rogue(char* charName);
        ~Rogue();

        virtual void attack(Unit* enemy);
};

#endif // ROGUE_H