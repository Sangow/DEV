#include "Berserker.h"

Berserker::Berserker(char* charName) : Unit(charName, "Berserker") {
    this->state = new UnitState(70);
    this->weapon = new Sword(this);
};

Berserker::~Berserker() {};

void Berserker::takeMagicDamage(float magicDmg) {
    std::cout << this->getCharName() << " cannot be attack by magic!" << std::endl;
};