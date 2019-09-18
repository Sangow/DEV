#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../interface/Soul.h"
#include "../interface/SoulHunter.h"
#include "../exceptions/Exceptions.cpp"
#include "../state/State.h"
// #include "../state/MagicState.h"
#include "../classAbility/ClassAbility.h"
#include "../weapon/Weapon.h"

class State;
class MagicState;
class Weapon;
class ClassAbility;

class Unit : public Soul, public SoulHunter {
    protected:
        State* state;
        // MagicState* mState;
        Weapon* weapon;
        ClassAbility* ability;
        std::string charName;
        std::string charClass;

        void changeCharClass(const std::string& newCharClass);

        void ensureIsAlive();

    public:
        Unit(const std::string& charName, const std::string& charClass);
        virtual ~Unit();

        // bool unitIsMage() const;
        
        double getHP() const;
        double getHPLimit() const;
        double getStrength() const;
        double getAgility() const;
        State& getState() const;
        
        double getDMG() const;
        Weapon& getWeapon() const;
        
        const std::string& getCharClass() const;
        const std::string& getCharName() const;

        virtual void takePhysDamage(double physDmg);
        virtual void takeMagicDamage(double magicDmg);
        virtual void increaseHP(double extraHP);

        // MagicState& getMagicState()const;
        virtual double getMana() const;
        virtual double getManaLimit() const;

        void changeWeapon(Weapon* newWeapon);
        void changeAbility(ClassAbility* newAbility);
        virtual void changeState(State* newState, const std::string& newCharClass);

        bool readyToBeInfected();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        void useAbility();
        void useAbility(Unit* enemy);

        virtual void notifySoulHunters() override;
        virtual void notifySouls() override;
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H