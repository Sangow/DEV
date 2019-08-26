obj: exceptions spells spellcasters states units weapons

exceptions:

spells:

spellcasters:

states:
	g++ ../state/State.cpp -c
	g++ ../state/MagicState.cpp -c
	g++ ../state/UnitState.cpp -c
	g++ ../state/VampireState.cpp -c
	g++ ../state/WerewolfState.cpp -c
	g++ ../state/WolfState.cpp -c
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
# 	g++ ../weapon/*.cpp -c

clean:
	rm -rf *.o