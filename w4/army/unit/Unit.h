#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../exceptions/Exceptions.h"
#include "../state/State.h"
#include "../state/MagicState.h"
#include "../classAbility/ClassAbility.h"
#include "../weapon/Weapon.h"

class State;
class MagicState;
class Weapon;
class ClassAbility;

class Unit {
    protected:
        State* state;
        MagicState* mState;
        Weapon* weapon;
        ClassAbility* ability;
        const char* charName;
        const char* charClass;

        void changeCharClass(const char* newCharClass);

    public:
        Unit(const char* charName, const char* charClass);
        ~Unit();

        bool unitIsMage() const;
        
        float getHP() const;
        float getHPLimit() const;
        float getStrength() const;
        float getAgility() const;
        State& getState() const;
        
        float getDMG() const;
        Weapon& getWeapon() const;
        
        const char* getCharClass() const;
        const char* getCharName() const;

        void takePhysDamage(float physDmg);
        void takeMagicDamage(float magicDmg);
        void increaseHP(float extraHP);

        MagicState& getMagicState()const;
        virtual float getMana() const;
        virtual float getManaLimit() const;
        // void spendMana(float cost);
        // void increaseMana(float extraMana);

        void changeWeapon(Weapon* newWeapon);
        void changeAbility(ClassAbility* newAbility);
        virtual void changeState(State* newState, const char* newCharClass);

        bool readyToBeInfected();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        void useAbility();
        void useAbility(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H