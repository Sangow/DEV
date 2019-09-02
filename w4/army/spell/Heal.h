#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "Spell.h"

class Heal : public Spell {
    public:
        Heal(MagicState* mState);
        ~Heal();

        virtual void action(Unit* enemy);
};

#endif // HEAL_H