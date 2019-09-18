#include "../exceptions/Exceptions.cpp"
#include "../spellbook/SpellBook.h"
#include "../spellbook/WizardSpellBook.h"
#include "../spellbook/HealerSpellBook.h"
#include "../spellbook/PriestSpellBook.h"
#include "../spellbook/WarlockSpellBook.h"
#include "../spellbook/NecromancerSpellBook.h"
#include "../spell/Spell.h"
#include "../spell/Fireball.h"
#include "../spell/Heal.h"
#include "../state/State.h"
#include "../state/MagicState.h"
#include "../state/HumanState.h"
#include "../state/UndeadState.h"
#include "../state/VampireState.h"
#include "../state/WerewolfState.h"
#include "../state/WolfState.h"
#include "../state/BerserkerState.h"
#include "../state/SoldierState.h"
#include "../state/RogueState.h"
#include "../state/DemonState.h"
#include "../state/WizardState.h"
#include "../state/HealerState.h"
#include "../state/PriestState.h"
#include "../state/WarlockState.h"
#include "../state/NecromancerState.h"
#include "../state/WizardMState.h"
#include "../state/HealerMState.h"
#include "../state/PriestMState.h"
#include "../state/WarlockMState.h"
#include "../state/NecromancerMState.h"
#include "../unit/Unit.h"
#include "../unit/Berserker.h"
#include "../unit/Rogue.h"
#include "../unit/Soldier.h"
#include "../unit/Werewolf.h"
#include "../unit/Vampire.h"
#include "../unit/Wizard.h"
#include "../unit/Warlock.h"
#include "../unit/Demon.h"
#include "../unit/Healer.h"
#include "../unit/Necromancer.h"
#include "../weapon/Weapon.h"
#include "../weapon/Dagger.h"
#include "../weapon/Sword.h"
#include "../weapon/Fangs.h"
#include "../weapon/Claws.h"
#include "../weapon/TwoHandedSword.h"
#include "../weapon/Mace.h"
#include "../weapon/Staff.h"
#include "../weapon/Scepter.h"
#include "../weapon/HolyChimes.h"
#include "../weapon/Chaplet.h"
#include "../weapon/Sickle.h"
#include "../interface/Soul.h"
#include "../interface/SoulHunter.h"

int main() {
    Necromancer* necro1 = new Necromancer("Necro1");
    Necromancer *necro2 = new Necromancer("Necro2");

    std::cout << *necro1 << std::endl;
    std::cout << *necro2 << std::endl;

    necro1->attack(necro2);
    // necro1->useAbility();

    std::cout << *necro1 << std::endl;
    std::cout << *necro2 << std::endl;

    necro1->attack(necro2);
    necro1->attack(necro2);
    necro1->attack(necro2);
    necro1->attack(necro2);
    necro1->attack(necro2);
    necro1->attack(necro2);
    necro1->attack(necro2);
    // necro1->attack(necro2);
    // necro1->attack(necro2);
    

    std::cout << *necro1 << std::endl;
    std::cout << *necro2 << std::endl;

    // std::cout << *war << std::endl;
    // std::cout << *necro << std::endl;

    // std::cout << necro1->getSoulHunters().size() << std::endl;

    return 0;
}