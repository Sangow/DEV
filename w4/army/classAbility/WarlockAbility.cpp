#include "WarlockAbility.h"

WarlockAbility::WarlockAbility(Unit* owner) : ClassAbility(owner) {};

WarlockAbility::~WarlockAbility() {
    if ( this->slave != NULL ) {
        delete this->slave;
    }
};

void WarlockAbility::useAbility() {
    this->summonSlave();
}

void WarlockAbility::useAbility(Unit* enemy) {
    if ( this->slave == NULL ) {
        std::cout << owner->getCharName() << ", your slave does not exist!" << std::endl;
        return;
    }
    this->slaveAttack(enemy);
};

void WarlockAbility::summonSlave() {
    try {
        dynamic_cast<SpellCaster*>(owner)->getMagicState().spendMana(20);
    } catch (OutOfManaException) {
        std::cout << owner->getCharName() << " cannot summon Demon. No mana!" << std::endl;
        return;
    }
    if ( this->slave != NULL ) {
        Demon* tmpDmn = this->slave;
        delete (tmpDmn);
    }
    this->slave = new Demon(this);
    std::cout << owner->getCharName() << " summoned Demon!" << std::endl;
};

void WarlockAbility::slaveAttack(Unit* enemy) {
    this->slave->attack(enemy);
};