#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "Unit.h"
#include "../state/UnitState.h"
#include "../weapon/Sword.h"

class Berserker : public Unit {
    public:
        Berserker(char* charName);
        ~Berserker();

        virtual void takeMagicDamage(float magicDmg);
};

#endif // BERSERKER_H