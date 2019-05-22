#include "demon.h"
#include "cyberdemon.h"
using namespace std;

namespace cs_creature {
	Cyberdemon::Cyberdemon() {
		setStrength(10);
		setHitpoints(10);
	}





	Cyberdemon::Cyberdemon(int newStrength, int newHitpoints) {
		setStrength(newStrength);
		setHitpoints(newHitpoints);
	}





	string Cyberdemon::getSpecies() const {
		return "Cyberdemon";
	}
}