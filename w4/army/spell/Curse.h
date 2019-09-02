#ifndef CURSE_H
#define CURSE_H

#include <iostream>
#include "Spell.h"

class Curse : public Spell {
    public:
        Curse();
        ~Curse();

        virtual void action(Unit* enemy);
};

#endif // CURSE_H