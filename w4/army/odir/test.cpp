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

int main() {
    Warlock* warlock = new Warlock("Kurva");
    Wizard* wizard = new Wizard("Perdun");

    std::cout << *warlock << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "============================" << std::endl;

    wizard->cast(warlock);

    std::cout << "============================" << std::endl;
    std::cout << *warlock << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "============================" << std::endl;

    wizard->changeSpell("Zalupa");
    wizard->changeSpell("Heal");

    wizard->cast(warlock);

    std::cout << "============================" << std::endl;
    std::cout << *warlock << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "============================" << std::endl;

    warlock->useAbility();

    std::cout << "============================" << std::endl;
    std::cout << *warlock << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "============================" << std::endl;

    warlock->useAbility(wizard);
    warlock->useAbility(wizard);

    std::cout << "============================" << std::endl;
    std::cout << *warlock << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "============================" << std::endl;

    wizard->attack(warlock);

    std::cout << "============================" << std::endl;
    std::cout << *warlock << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "============================" << std::endl;

    warlock->useAbility();

    std::cout << "============================" << std::endl;
    std::cout << *warlock << std::endl;
    std::cout << *wizard << std::endl;
    std::cout << "============================" << std::endl;

    return 0;
}