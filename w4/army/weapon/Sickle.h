// Warlock weapon
#ifndef SICKLE_H
#define SICKLE_H

#include <iostream>
#include "Weapon.h"

class Sickle : public Weapon {
    public:
        Sickle(Unit* owner);
        ~Sickle();
};

#endif // SICKLE_H