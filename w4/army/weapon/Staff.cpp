#include "Staff.h"

Staff::Staff(Unit* owner) : Weapon("Staff", 7, owner) {};

Staff::~Staff() {};

void Staff::cast(const char* spellName, Unit* enemy) {};