#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions/Exceptions.h"

class State {
    protected:
        float hp;
        float hpLimit;
        float dmg;
        const char* title;

        void ensureIsAlive();

    public:
        State(float hp, float dmg, const char* title);
        virtual ~State();

        float getHP() const;
        float getHPLimit() const;
        float getDMG() const;
        const char* getTitle() const;

        virtual void takeDamage(float dmg);
        virtual void increaseHP(float hp);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H