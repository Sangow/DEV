#include "Fangs.h"

Fangs::Fangs(Unit* owner) : Weapon("Fangs", 40, owner), infectionChance(1) {};

Fangs::~Fangs() {};

void Fangs::action(Unit* enemy, float dmg) {
    enemy->takePhysDamage(dmg);

    // enemy->state->ensureIsAlive();

    if ( this->infectionChance % 2 == 0 && enemy->readyToBeInfected() ) {
        enemy->changeState(new WolfState(enemy->getHP()*2, enemy->getHPLimit()*2));
        std::cout << "INFECTED!!!" << std::endl;
    }

    infectionChance += 1;
};