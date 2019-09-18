#include "Necromancer.h"

Necromancer::Necromancer(const std::string& charName) : SpellCaster(charName, "Necromancer") {
    this->state = new NecromancerState();
    this->mState = new NecromancerMState();
    this->weapon = new Chaplet(this);
};

Necromancer::~Necromancer() {};

void Necromancer::takePhysDamage(double physDmg) {
    this->state->takePhysDamage(physDmg);

    if ( this->getHP() == 0 ) {
        this->notifySoulHunters();
        this->notifySouls();
    }
};

void Necromancer::takeMagicDamage(double magicDmg) {
    this->state->takeMagicDamage(magicDmg);

    if ( this->getHP() == 0 ) {
        this->notifySoulHunters();
        this->notifySouls();
    }
};

void Necromancer::attack(Unit* enemy) {
    try {
        std::cout << this->getCharName() << " attacks " << enemy->getCharName() << std::endl;
        this->weapon->attack(enemy);

        if ( this->unitIsMage() && enemy->getHP() > 0 ) {
            this->addSoul(enemy);
        }
    } catch (OutOfHPException e) {
        std::cout << this->getCharName() << " cannot attack " << enemy->getCharName() << ": " << e.message << std::endl;
    }
};

void Necromancer::counterAttack(Unit* enemy) {
    try {
        std::cout << this->getCharName() << " counterAttacks " << enemy->getCharName() << std::endl;
        this->weapon->counterAttack(enemy);

        if ( this->unitIsMage() && enemy->getHP() > 0 ) {
            this->addSoul(enemy);
        }
    } catch (OutOfHPException e) {
        std::cout << this->getCharName() << " cannot counterAttack " << enemy->getCharName() << ": " << e.message << std::endl;
    }
};

void Necromancer::cast(Unit* enemy) {
    if ( this->unitIsMage() ) {
        try {
            this->mState->getSpellBook().action(enemy);
            std::cout << this->getCharName() << " casts " << enemy->getCharName() << std::endl;

            if ( enemy->getHP() != 0 ) {
                this->addSoul(enemy);
            }
        } catch (OutOfHPException e) {
            std::cout << this->getCharName() << " cannot cast " << enemy->getCharName() << ": " << e.message << std::endl;
        } catch (OutOfManaException e) {
            std::cout << this->getCharName() << " cannot cast: " << e.message << std::endl;
        }
    } else {
        std::cout << this->getCharName() << " no longer a mage." << std::endl;
    }
};