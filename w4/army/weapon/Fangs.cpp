#include "Fangs.h"

Fangs::Fangs(Unit* owner) : Weapon("Fangs", owner), infectionChance(1) {
    this->dmg = this->owner->getStrength() * 20;
};

Fangs::~Fangs() {};

void Fangs::infect(Unit* enemy) {
    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {
        float enemyHP = enemy->getHP();

        enemy->changeState(new WolfState());
        enemy->takePhysDamage(this->owner->getHPLimit() - (enemyHP * this->owner->getHPLimit()) / 100);
        enemy->changeWeapon(new Fangs(enemy));
        std::cout << enemy->getCharName() << " becomes Wolf!" << std::endl;
    }
    this->infectionChance += 1;
};

void Fangs::attack(Unit* enemy) {
    std::cout << owner->getCharName() << " attacks " << enemy->getCharName() << std::endl;
    enemy->takePhysDamage(this->dmg);
    enemy->counterAttack(owner);
    
    infect(enemy);
};