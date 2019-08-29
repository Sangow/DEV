#include "Fangs.h"

Fangs::Fangs(Unit* owner) : Weapon("Fangs", 40, owner), infectionChance(1) {};

Fangs::~Fangs() {};

void Fangs::infect(Unit* enemy) {
    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {
        enemy->changeState(new WolfState(enemy->getHP()*2, enemy->getHPLimit()*2));
        enemy->changeWeapon(new Fangs(enemy));
        std::cout << enemy->getCharName() << " becomes Wolf!" << std::endl;
    }
    this->infectionChance += 1;
};

void Fangs::attack(Unit* enemy) {
    enemy->takePhysDamage(this->dmg);

    infect(enemy);
};