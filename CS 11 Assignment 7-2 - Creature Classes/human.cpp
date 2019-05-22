#include "creature.h"
#include "human.h"
#include <string>
using namespace std;

namespace cs_creature {
	Human::Human() {}





	Human::Human(int newStrength, int newHitpoints) {
		setStrength(newStrength);
		setHitpoints(newHitpoints);
	}





	string Human::getSpecies() const {
		return "Human";
	}
}