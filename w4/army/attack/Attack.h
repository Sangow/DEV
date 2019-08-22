#ifndef ATACK_H
#define ATACK_H

#include <iostream>
#include "../unit/Unit.h"

class Unit;

class Attack {
    protected:
        Unit* instance;

    public:
        Attack(Unit* instance);
        virtual ~Attack();
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // ATACK_H