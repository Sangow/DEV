#include "SoulHunter.h"

SoulHunter::SoulHunter() {};

SoulHunter::~SoulHunter() {
    for ( std::set<Soul*>::iterator it = souls.begin(); it != souls.end(); it++ ) {
        (*it)->removeSoulHunter(this);
    }
};

void SoulHunter::addSoul(Soul* soul) {
    this->souls.insert(soul);
    soul->addSoulHunter(this);
};

void SoulHunter::removeSoul(Soul* soul) {
    this->souls.erase(soul);
};

const std::set<Soul*>& SoulHunter::getSouls() {
    return this->souls;
};