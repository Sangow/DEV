// Healer weapon
#ifndef SCEPTER_H
#define SCEPTER_H

#include <iostream>
#include "Weapon.h"

class Scepter : public Weapon {
    public:
        Scepter(Unit* owner);
        ~Scepter();
};

#endif // SCEPTER_H