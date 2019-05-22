#ifndef DEMON
#define DEMON
#include "creature.h"
#include <string>
namespace cs_creature {
	class Demon : public Creature {
	public:
		Demon();
		Demon(int newStrength, int newHitpoints);
		std::string getSpecies() const;
		int getDamage() const;
	};
}
#endif