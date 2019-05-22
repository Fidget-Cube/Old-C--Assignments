#include "creature.h"
#include "elf.h"
#include <iostream>
#include <string>
using namespace std;

namespace cs_creature {
	Elf::Elf() {
		setStrength(10);
		setHitpoints(10);
	}





	Elf::Elf(int newStrength, int newHitpoints) {
		setStrength(newStrength);
		setHitpoints(newHitpoints);
	}





	string Elf::getSpecies() const {
		return "Elf";
	}





	int Elf::getDamage() const {
		int damage = Creature::getDamage();
		if ((rand() % 2) == 0) {
			cout << "Magical attack deals " << damage << " additional damage!" << endl;
			damage *= 2;
		}
		return damage;
	}
}