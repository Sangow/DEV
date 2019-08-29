#ifndef FIREBALL_H
#define FIREBALL_H

#include <iostream>
#include "Spell.h"

class Fireball : public Spell {
    public:
        Fireball();
        ~Fireball();

        virtual void action(Unit* enemy);
};

#endif // FIREBALL