// Rogue weapon
#ifndef DAGGER_H
#define DAGGER_H

#include <iostream>
#include "Weapon.h"

class Dagger : public Weapon {
    public:
        Dagger(Unit* owner);
        ~Dagger();

        virtual void attack(Unit* enemy) override;
};

#endif // DAGGER_H