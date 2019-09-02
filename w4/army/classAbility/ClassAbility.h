#ifndef CLASS_ABILITY_H
#define CLASS_ABILITY_H

#include <iostream>
#include "../unit/Unit.h"

class Unit;

class ClassAbility {
    protected:
        Unit* owner;
    public:
        ClassAbility(Unit* owner);
        virtual ~ClassAbility();

        virtual void useAbility() = 0;
        virtual void useAbility(Unit* enemy) = 0;
};

#endif // CLASS_ABILITY_H