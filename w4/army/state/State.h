#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions/Exceptions.h"

class State {
    protected:
        float hp;
        float hpLimit;

        void ensureIsAlive();

    public:
        State(float hp, float dmg);
        virtual ~State();

        float getHP() const;
        float getHPLimit() const;

        virtual void takePhysDamage(float physDmg);
        virtual void takePhysDamage(float Magicdmg);
        virtual void increaseHP(float extraHP);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H