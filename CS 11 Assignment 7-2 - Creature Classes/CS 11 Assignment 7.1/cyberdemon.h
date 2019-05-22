#include "demon.h"
#include <string>
namespace cs_creature {
	class Cyberdemon : public Demon {
	public:
		Cyberdemon();
		Cyberdemon(int newStrength, int newHitpoints);
		std::string getSpecies() const;
	};
}