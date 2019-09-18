#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "SpellCaster.h"
#include "../interface/SoulHunter.h"
#include "../state/NecromancerState.h"
#include "../state/NecromancerMState.h"
#include "../weapon/Chaplet.h"

class Necromancer : public SpellCaster {
    public:
        Necromancer(const std::string& charName);
        ~Necromancer();

        virtual void takePhysDamage(double physDmg) override;
        virtual void takeMagicDamage(double magicDmg) override;

        virtual void attack(Unit* enemy) override;
        virtual void counterAttack(Unit* enemy) override;

        virtual void cast(Unit* enemy) override;
};

#endif // NECROMANCER_H