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

// Think to be useless, BUT
void WarlockAbility::useAbility(Unit* enemy) {
    std::cout << owner->getCharName() << ", nothing to do with this enemy unit!" << std::endl;
};

void WarlockAbility::summonSlave() {
    owner->getMagicState().spendMana(20);

    if ( this->slave != NULL ) {
        Demon* tmpDmn = this->slave;
        delete (tmpDmn);
    }
    this->slave = new Demon(this);
    std::cout << owner->getCharName() << " summoned Demon!" << std::endl;
};

// void WarlockAbility::freeSlave() {
//     Demon* tmpDmn = this->slave;
//     delete (tmpDmn);
//     this->slave = NULL;
// };