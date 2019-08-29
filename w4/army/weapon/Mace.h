#ifndef MACE_H
#define MACE_H

#include <iostream>
#include "Weapon.h"

class Mace : public Weapon {
    public:
        Mace(Unit* owner);
        ~Mace();
};

#endif // MACE_H