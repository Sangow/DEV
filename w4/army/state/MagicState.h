#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions/Exceptions.h"

class MagicState {
    protected:
        float mana;
        float manaLimit;

    public:
        MagicState(float mana);
        virtual ~MagicState();

        float getMana() const;
        float getManaLimit() const;

        virtual void spendMana(float cost);
        virtual void increaseMana(float mana);
};

std::ostream& operator<<(std::ostream& out, const MagicState* magicState);

#endif // MAGIC_STATE_H