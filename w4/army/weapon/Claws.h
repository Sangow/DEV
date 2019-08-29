#ifndef CLAWS_H
#define CLAWS_H

// Vampire weapon

#include <iostream>
#include "Weapon.h"
#include "../state/VampireState.h"

class Claws : public Weapon {
    protected:
        int infectionChance;

    public:
        Claws(Unit* owner);
        ~Claws();

        void infect(Unit* enemy);

        virtual void attack(Unit* enemy);

};

#endif // CLAWS_H