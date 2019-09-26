#include "SpellCaster.h"

bool SpellCaster::unitIsMage() const {
    return this->mState != NULL;
};

SpellCaster::SpellCaster(const std::string& charName, const std::string& charClass) : Unit(charName, charClass) {};

SpellCaster::~SpellCaster() {};

double SpellCaster::getMana() const {
    if ( this->unitIsMage() ) {
        return this->mState->getMana();
    }
    Unit::getMana();
};

double SpellCaster::getManaLimit() const {
    if ( this->unitIsMage() ) {
        return this->mState->getManaLimit();
    }
    Unit::getManaLimit();
};

double SpellCaster::getIntellect() const {
    if ( this->unitIsMage() ) {
        return this->mState->getIntellect();
    }
    std::cout << this->getCharName() << " no longer a mage." << std::endl;
};

double SpellCaster::getFaith() const {
    if ( this->unitIsMage() ) {
        return this->mState->getFaith();
    }
    std::cout << this->getCharName() << " no longer a mage." << std::endl;
};

const std::string& SpellCaster::getCurrentSpell() const {
    return this->mState->getSpellBook().getCurrentSpell().getSpellName();
};

MagicState& SpellCaster::getMagicState() const {
    return *(this->mState);
};

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
        try {
            this->mState->getSpellBook().action(enemy);
            std::cout << this->getCharName() << " casts " << enemy->getCharName() << std::endl;
        } catch (OutOfHPException exc) {
            std::cout << this->getCharName() << " cannot cast " << enemy->getCharName() << ": " << exc.message << std::endl;
        } catch (OutOfManaException exc) {
            std::cout << this->getCharName() << " cannot cast: " << exc.message << std::endl;
        }
    } else {
        std::cout << this->getCharName() << " no longer a mage." << std::endl;
    }
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellcaster) {
    out << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    out << spellcaster.getCharClass() << ": " << spellcaster.getCharName() << std::endl;
    out << spellcaster.getState();
    out << " [";
    out << "mana: " << spellcaster.getMana() << "/" << spellcaster.getManaLimit();
    out << "]" << std::endl;
    out << spellcaster.getWeapon() << std::endl;
    out << "Spell: ";
    out << (spellcaster.unitIsMage() ? spellcaster.getCurrentSpell() : "NOSPELL") << std::endl;
    out << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";

    return out;
};