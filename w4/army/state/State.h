#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions/Exceptions.h"
#include "../unit/Unit.h"

class State {
    protected:
        float hp;
        float hpLimit;
        float strength;
        float agility;

    public:
        bool isVampire;
        bool isUndead;
        bool isWerewolf;
        bool isWolf;

        void ensureIsAlive();

        State(float hp);
        State(float hp, float hpLimit);
        virtual ~State();

        float getHP() const;
        float getHPLimit() const;
        float getStrength() const;
        float getAgility() const;

        bool readyToBeInfected();

        virtual void takePhysDamage(float physDmg);
        virtual void takeMagicDamage(float magicDmg);

        virtual void increaseHP(float extraHP);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H