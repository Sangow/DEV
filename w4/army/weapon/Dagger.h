#ifndef DAGGER_H
#define DAGGER_H

#include <iostream>
#include "Weapon.h"

class Dagger : public Weapon {
    public:
        Dagger(Unit* owner);
        ~Dagger();
};

#endif // DAGGER_H