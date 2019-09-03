#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../interface/Soul.h"
#include "../exceptions/Exceptions.h"
#include "../state/State.h"
#include "../state/MagicState.h"
#include "../classAbility/ClassAbility.h"
#include "../weapon/Weapon.h"

class State;
class MagicState;
class Weapon;
class ClassAbility;

class Unit : public Soul {
    protected:
        State* state;
        MagicState* mState;
        Weapon* weapon;
        ClassAbility* ability;
        std::string charName;
        std::string charClass;

        void changeCharClass(const std::string& newCharClass);

    public:
        Unit(const std::string& charName, const std::string& charClass);
        virtual ~Unit();

        bool unitIsMage() const;
        
        float getHP() const;
        float getHPLimit() const;
        float getStrength() const;
        float getAgility() const;
        State& getState() const;
        
        float getDMG() const;
        Weapon& getWeapon() const;
        
        const std::string& getCharClass() const;
        const std::string& getCharName() const;

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
        virtual void changeState(State* newState, const std::string& newCharClass);

        bool readyToBeInfected();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        void useAbility();
        void useAbility(Unit* enemy);

        virtual void notifySoulHunters();
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H