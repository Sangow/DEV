#ifndef CLASS_ABILITY_H
#define CLASS_ABILITY_H

#include <iostream>
#include "../unit/Unit.h"

class ClassAbility {
    protected:
        Unit* unit;

    public:
        ClassAbility(Unit* unit);
        virtual ~ClassAbility();

        virtual void ability() = 0;
}

#endif // CLASS_ABILITY_H