#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions/Exceptions.cpp"
#include "../unit/Unit.h"

class State {
    protected:
        double hp;
        double hpLimit;
        double strength;
        double agility;

    public:
        bool isVampire;
        bool isUndead;
        bool isWerewolf;

        State(double hp);
        virtual ~State();

        double getHP() const;
        double getHPLimit() const;
        double getStrength() const;
        double getAgility() const;

        bool readyToBeInfected();

        virtual void takePhysDamage(double physDmg);
        virtual void takeMagicDamage(double magicDmg);

        virtual void increaseHP(double extraHP);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H