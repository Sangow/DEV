#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "Unit.h"
#include "../state/BerserkerState.h"
#include "../weapon/TwoHandedSword.h"

class Berserker : public Unit {
    public:
        Berserker(const char* charName);
        ~Berserker();
};

#endif // BERSERKER_H