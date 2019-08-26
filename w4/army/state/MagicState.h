#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions/Exceptions.h"
#include "UnitState.h"

class MagicState : public UnitState {
    protected:
        float mana;
        float manaLimit;

    public:
        MagicState(float hp, float mana);
        virtual ~MagicState();

        float getMana() const;
        float getManaLimit() const;

        virtual void spendMana(float cost);
        virtual void increaseMana(float extraMana);
};

std::ostream& operator<<(std::ostream& out, const MagicState* magicState);

#endif // MAGIC_STATE_H