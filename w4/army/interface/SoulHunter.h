#ifndef SOULHUNTER_H
#define SOULHUNTER_H

#include <iostream>
#include <set>
#include "Soul.h"

class Soul;

class SoulHunter {
    private:
        std::set<Soul*> souls;
    public:
        SoulHunter();
        ~SoulHunter();

        void addSoul(Soul* Soul);
        void removeSoul(Soul* Soul);

        const std::set<Soul*>& getSouls();

        virtual void notifySouls() = 0;
};

#endif // SOULHUNTER_H