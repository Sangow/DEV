#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"
#include "../state/SoldierState.h"
#include "../weapon/Sword.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& charName);
        ~Soldier();
};

#endif // SOLDIER_H