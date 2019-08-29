#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions/Exceptions.h"

class MagicState {
    protected:
        float mana;
        float manaLimit;
        float intellect;
        float faith;

    public:
        MagicState(float mana, float intellect, float faith);
        virtual ~MagicState();

        float getMana() const;
        float getManaLimit() const;
        float getIntellect() const;
        float getFaith() const;

        virtual void spendMana(float cost);
        virtual void increaseMana(float extraMana);
};

std::ostream& operator<<(std::ostream& out, const MagicState* magicState);

#endif // MAGIC_STATE_H