#ifndef CREATURE
#define CREATURE
#include <string>
namespace cs_creature {
	class Creature {
	private:
		int strength;
		int hitpoints;
	public:
		Creature();
		Creature(int newStrength, int newHitpoints);
		int getStrength() const;
		int getHitpoints() const;
		void setStrength(int newStrength);
		void setHitpoints(int newHitpoints);
		virtual std::string getSpecies() const = 0;
		virtual int getDamage() const;
	};
}
#endif