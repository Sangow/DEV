#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"
#include "../state/UnitState.h"
#include "../weapon/Sword.h"

class Soldier : public Unit {
    public:
        Soldier(char* charName);
        ~Soldier();
};

#endif // SOLDIER_H