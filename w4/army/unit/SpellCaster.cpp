#include "SpellCaster.h"

SpellCaster::SpellCaster(const std::string& charName, const std::string& charClass) 
    : Unit(charName, charClass) {};

SpellCaster::~SpellCaster() {};

float SpellCaster::getMana() const {
    if ( this->unitIsMage() ) {
        return this->mState->getMana();
    }
    Unit::getMana();
};

float SpellCaster::getManaLimit() const {
    if ( this->unitIsMage() ) {
        return this->mState->getManaLimit();
    }
    Unit::getManaLimit();
};

float SpellCaster::getIntellect() const {
    if ( this->unitIsMage() ) {
        return this->mState->getIntellect();
    }
    std::cout << this->getCharName() << " no longer a mage." << std::endl;
};

float SpellCaster::getFaith() const {
    if ( this->unitIsMage() ) {
        return this->mState->getFaith();
    }
    std::cout << this->getCharName() << " no longer a mage." << std::endl;
};

MagicState& SpellCaster::getMagicState() const {
    return *(this->mState);
};

// void SpellCaster::spendMana(float cost) {
//     if ( this->unitIsMage() ) {
//         this->mState->spendMana(cost);
//         return;
//     }
//     std::cout << this->getCharName() << " no longer a mage." << std::endl;
// };

// void SpellCaster::increaseMana(float extraMana) {
//     if ( this->unitIsMage() ) {
//         this->mState->increaseMana(extraMana);
//         return;
//     }
//     std::cout << this->getCharName() << " no longer a mage." << std::endl;
// };

void SpellCaster::changeState(State* newState, const std::string& newCharClass) {
    if ( this->unitIsMage() ) {
        this->cleanMState();
    }
    State* tmpState = this->state;
    delete (tmpState);
    this->state = newState;
    this->changeCharClass(newCharClass);
};

void SpellCaster::cleanMState() {
    MagicState* tmpMState = this->mState;
    this->mState = NULL;
    delete (tmpMState);
};

void SpellCaster::changeSpell(const std::string& spellName) {
    if ( this->unitIsMage() ) {
        this->mState->getSpellBook().changeSpell(spellName);
    } else {
        std::cout << this->getCharName() << " no longer a mage." << std::endl;
    }
};

void SpellCaster::cast(Unit* enemy) {
    if ( this->unitIsMage() ) {
        std::cout << this->getCharName() << " casts " << enemy->getCharName() << std::endl;
        this->mState->getSpellBook().action(enemy);
    } else {
        std::cout << this->getCharName() << " no longer a mage." << std::endl;
    }
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellcaster) {
    out << spellcaster.getCharClass() << ": " << spellcaster.getCharName();
    out << spellcaster.getState();
    out << spellcaster.getWeapon() << std::endl;
    out << spellcaster.getMagicState();

    return out;
};
