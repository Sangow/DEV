#ifndef SOUL_H
#define SOUL_H

#include <iostream>
#include <set>
#include "SoulHunter.h"

class SoulHunter;

class Soul {
    private:
        std::set<SoulHunter*> soulHunters;
    public:
        Soul();
        ~Soul();

        void addSoulHunter(SoulHunter* soulHunters);
        void removeSoulHunter(SoulHunter* soulHunters);

        const std::set<SoulHunter*>& getSoulHunters();

        virtual void notifySoulHunters() = 0;
};


#endif // SOUL_H