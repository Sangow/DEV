#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include "Unit.h"
#include "../classAbility/WarlockAbility.h"
#include "../classAbility/ClassAbility.h"
#include "../state/DemonState.h"
#include "../weapon/Sword.h"

class WarlockAbility;

class Demon : public Unit {
    protected:
        ClassAbility* overlord;
    public:
        Demon(WarlockAbility* overlord);
        ~Demon();
};

#endif // DEMON_H