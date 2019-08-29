#ifndef UNIT_H
#define UNIT_H

#include "../exceptions/Exceptions.h"
#include "../state/State.h"
#include "../state/MagicState.h"
#include "../weapon/Weapon.h"

class State;
class MagicState;
class Weapon;

class Unit {
    protected:
        State* state;
        MagicState* mState;
        Weapon* weapon;
        const char* charName;
        const char* charClass;

    public:
        Unit(const char* charName, const char* charClass);
        ~Unit();
        
        float getHP() const;
        float getHPLimit() const;
        float getStrength() const;
        float getAgility() const;
        State& getState() const;
        
        float getDMG() const;
        Weapon& getWeapon() const;

        virtual float getMana() const;
        virtual float getManaLimit() const;
        virtual float getIntellect() const;
        virtual float getFaith() const;
        
        const char* getCharClass() const;
        const char* getCharName() const;

        void takePhysDamage(float physDmg);
        void takeMagicDamage(float magicDmg);
        void increaseHP(float extraHP);

        void changeState(State* newState);
        void changeWeapon(Weapon* newWeapon);
        void cleanMState(Unit* enemy);

        bool readyToBeInfected();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H