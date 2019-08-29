obj: exceptions spells spellcasters states units weapons

exceptions:

spells:
	g++ ../spell/Spell.cpp -c
	g++ ../spell/Fireball.cpp -c
	g++ ../spell/Heal.cpp -c

spellcasters:
# 	g++ ../spellcaster/SpellCaster.cpp -c

states:
	g++ ../state/State.cpp -c
	g++ ../state/MagicState.cpp -c
	g++ ../state/HumanState.cpp -c
	g++ ../state/VampireState.cpp -c
	g++ ../state/WerewolfState.cpp -c
	g++ ../state/WolfState.cpp -c
	g++ ../state/NecromancerState.cpp -c
	g++ ../state/BerserkerState.cpp -c
# 	g++ ../state/*.cpp -c

units:
	g++ ../unit/Unit.cpp -c
	g++ ../unit/Berserker.cpp -c
	g++ ../unit/Rogue.cpp -c
	g++ ../unit/Soldier.cpp -c
	g++ ../unit/Werewolf.cpp -c
	g++ ../unit/Vampire.cpp -c
# 	g++ ../unit/*.cpp -c

weapons:
	g++ ../weapon/Weapon.cpp -c
	g++ ../weapon/Dagger.cpp -c
	g++ ../weapon/Sword.cpp -c
	g++ ../weapon/Fangs.cpp -c
	g++ ../weapon/Claws.cpp -c
	g++ ../weapon/TwoHandedSword.cpp -c
	g++ ../weapon/Mace.cpp -c
	g++ ../weapon/Staff.cpp -c
# 	g++ ../weapon/*.cpp -c

clean:
	rm -rf *.o