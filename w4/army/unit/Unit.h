#ifndef UNIT_H
#define UNIT_H

#include "../state/State.h"
#include "../exceptions/Exceptions.h"
#include "../attack/Weapon.h"

class Attack;

class Unit {
    protected:
        State* state;
        Weapon* weapon;

    public:
        Unit(float hp, float dmg, const char* title);
        ~Unit();
        
        float getHP() const;
        float getHPLimit() const;
        float getDMG() const;
        const char* getTitle() const;
        State& getState() const;

        virtual void takePhysDamage(float dmg);
        virtual void takeMagicDamage(float dmg);
        virtual void increaseHP(float hp);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H