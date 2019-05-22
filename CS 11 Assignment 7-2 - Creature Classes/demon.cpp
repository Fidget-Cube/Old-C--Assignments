#include "creature.h"
#include "demon.h"
#include <iostream>
#include <string>
using namespace std;

namespace cs_creature {
	Demon::Demon() {
		setStrength(10);
		setHitpoints(10);
	}





	Demon::Demon(int newStrength, int newHitpoints) {
		setStrength(newStrength);
		setHitpoints(newHitpoints);
	}





	string Demon::getSpecies() const {
		return "Demon";
	}





	int Demon::getDamage() const {
		int damage = Creature::getDamage();
		if ((rand() % 4) == 0) {
			damage += 50;
			cout << "Demonic attack inflicts 50 additional damage!" << endl;
		}
		return damage;
	}
}