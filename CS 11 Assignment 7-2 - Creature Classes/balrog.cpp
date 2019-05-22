#include "demon.h"
#include "balrog.h"
#include <iostream>
#include <string>
using namespace std;

namespace cs_creature {
	Balrog::Balrog() {
		setStrength(10);
		setHitpoints(10);
	}





	Balrog::Balrog(int newStrength, int newHitpoints) {
		setStrength(newStrength);
		setHitpoints(newHitpoints);
	}





	string Balrog::getSpecies() const {
		return "Balrog";
	}





	int Balrog::getDamage() const {
		int damage = Demon::getDamage();
		int damage2 = (rand() % getStrength()) + 1;
		cout << "Balrog speed attack deals " << damage2 << " additional damage!" << endl;
		return damage += damage2;
	}
}