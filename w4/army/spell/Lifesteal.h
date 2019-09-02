#ifndef LIFESTEAL_H
#define LIFESTEAL_H

#include <iostream>
#include "Spell.h"

class Lifesteal : public Spell {
    public:
        Lifesteal();
        ~Lifesteal();

        virtual void action(Unit* enemy);
};

#endif // LIFESTEAL_H