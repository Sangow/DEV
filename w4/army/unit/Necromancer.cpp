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
        this->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << this->getCharName() << " cannot attack " << enemy->getCharName() << ": " << this->getCharName() << e.message << std::endl;
        return;
    }

    if ( this->unitIsMage() && enemy->getHP() > 0 ) {
        this->addSoul(enemy);
    }

    try {
        enemy->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << enemy->getCharName() << " cannot be attacked by " << this->getCharName() << ": " << enemy->getCharName() << e.message << std::endl;
        return;
    }

    std::cout << this->getCharName() << " attacks " << enemy->getCharName() << std::endl;
    this->weapon->attack(enemy);
};

void Necromancer::counterAttack(Unit* enemy) {
    try {
        this->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << this->getCharName() << " cannot counterAttack " << enemy->getCharName() << ": " << this->getCharName() << e.message << std::endl;
        return;
    }

    if ( this->unitIsMage() && enemy->getHP() > 0 ) {
        this->addSoul(enemy);
    }

    try {
        enemy->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << enemy->getCharName() << " cannot be counterAttacked by " << this->getCharName() << ": " << enemy->getCharName() << e.message << std::endl;
        return;
    }

    std::cout << this->getCharName() << " counterAttacks " << enemy->getCharName() << std::endl;
    this->weapon->counterAttack(enemy);
};

void Necromancer::cast(Unit* enemy) {
    if ( this->unitIsMage() ) {
        try {
            this->ensureIsAlive();
        } catch (OutOfHPException e) {
            std::cout << this->getCharName() << " cannot cast on " << enemy->getCharName() << ": " << this->getCharName() << e.message << std::endl;
            return;
        } catch (OutOfManaException e) {
            std::cout << this->getCharName() << " cannot cast: " << e.message << std::endl;
            return;
        }

        try {
            enemy->ensureIsAlive();
        } catch (OutOfHPException e) {
            std::cout << enemy->getCharName() << " cannot be casted by " << this->getCharName() << ": " << enemy->getCharName() << e.message << std::endl;
            return;
        }

        this->mState->getSpellBook().action(enemy);
        std::cout << this->getCharName() << " casts " << enemy->getCharName() << std::endl;
    } else {
        std::cout << this->getCharName() << " no longer a mage." << std::endl;
    }
};