#ifndef RESURRECT_H
#define RESURRECT_H

#include <iostream>
#include "Spell.h"

class Resurrect : public Spell {
    public:
        Resurrect();
        ~Resurrect();

        virtual void action(Unit* enemy);
};

#endif // RESURRECT_H