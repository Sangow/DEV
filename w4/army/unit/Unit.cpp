#include "Unit.h"

void Unit::changeCharClass(const std::string& newCharClass) {
    this->charClass = newCharClass;
};

void Unit::ensureIsAlive() {
    if ( this->getHP() == 0 ) {
        throw OutOfHPException();
    }
};

Unit::Unit(const std::string& charName, const std::string& charClass) : charClass(charClass), charName(charName) {};

Unit::~Unit() {
    delete this->state;
    delete this->ability;
    delete this->weapon;
};

double Unit::getHP() const {
    return this->state->getHP();
};

double Unit::getHPLimit() const {
    return this->state->getHPLimit();
};

double Unit::getStrength() const {
    return this->state->getStrength();
};

double Unit::getAgility() const {
    return this->state->getAgility();
};

double Unit::getDMG() const {
    return this->weapon->getDMG();
};

State& Unit::getState() const {
    return *(this->state);
};

Weapon& Unit::getWeapon() const {
    return *(this->weapon);
};

double Unit::getMana() const {
    return 0;
};

double Unit::getManaLimit() const {
    return 0;
};

const std::string& Unit::getCharClass() const {
    return this->charClass;
};

const std::string& Unit::getCharName() const {
    return this->charName;
};

void Unit::takePhysDamage(double physDmg) {
    this->state->takePhysDamage(physDmg);

    if ( this->getHP() == 0 ) {
        notifySoulHunters();
    }
};

void Unit::takeMagicDamage(double magicDmg) {
    this->state->takeMagicDamage(magicDmg);

    if ( this->getHP() == 0 ) {
        notifySoulHunters();
    }
};

void Unit::increaseHP(double extraHP) {
    this->state->increaseHP(extraHP);
};

void Unit::changeState(State* newState, const std::string& newCharClass) {
    State* tmpState = this->state;
    delete (tmpState);
    this->state = newState;
    this->changeCharClass(newCharClass);
};

void Unit::changeWeapon(Weapon* newWeapon) {
    Weapon* tmpWeapon = this->weapon;
    delete (tmpWeapon);
    this->weapon = newWeapon;
};

void Unit::changeAbility(ClassAbility* newAbility) {
    if ( this->ability != NULL ) {
        ClassAbility* tmpAbility = this->ability;
        delete (tmpAbility);
    }
    this->ability = newAbility;
};

bool Unit::readyToBeInfected() {
    return this->state->readyToBeInfected();
};

void Unit::attack(Unit* enemy) {
    try {
        this->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << this->getCharName() << " cannot attack " << enemy->getCharName() << ": " << this->getCharName() << e.message << std::endl;
        return;
    }

    std::cout << this->getCharName() << " attacks " << enemy->getCharName() << std::endl;
    this->weapon->attack(enemy);

void Unit::counterAttack(Unit* enemy) {
    try {
        this->ensureIsAlive();
    } catch (OutOfHPException e) {
        std::cout << this->getCharName() << " cannot counterAttack " << enemy->getCharName() << ": " << e.message << std::endl;
    }

    std::cout << this->getCharName() << " counterAttacks " << enemy->getCharName() << std::endl;
    this->weapon->counterAttack(enemy);
};

void Unit::useAbility() {
    if ( this->ability == NULL ) {
        std::cout << this->getCharName() << " has no ability!" << std::endl;
        return;
    }
    this->ability->useAbility();
};

void Unit::useAbility(Unit* enemy) {
    if ( this->ability == NULL ) {
        std::cout << this->getCharName() << " has no ability!" << std::endl;
        return;
    }
    this->ability->useAbility(enemy);
};

void Unit::notifySoulHunters() {
    for ( std::set<SoulHunter*>::iterator it = this->getSoulHunters().begin(); it != this->getSoulHunters().end(); it++ ) {
        (dynamic_cast<Unit*>(*it))->increaseHP(this->getHPLimit() / 10);
        (*it)->removeSoul(this);
    }
};

void Unit::notifySouls() {
    for ( std::set<Soul*>:: iterator it = this->getSouls().begin(); it != this->getSouls().end(); it++ ) {
        std::cout << this->getCharName() << " notifies " << (dynamic_cast<Unit*>(*it))->getCharName() << " that he is DEAD!" << std::endl;
        (*it)->removeSoulHunter(this);
    }
};

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    out << unit.getCharClass() << ": " << unit.getCharName() << std::endl;
    out << unit.getState();
    out << " [";
    out << "mana: " << unit.getMana() << "/" << unit.getManaLimit();
    out << "]" << std::endl;
    out << unit.getWeapon() << std::endl;
    out << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    return out;
};