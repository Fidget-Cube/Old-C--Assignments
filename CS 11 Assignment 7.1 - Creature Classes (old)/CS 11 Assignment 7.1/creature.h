#include <iostream>
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
		std::string getSpecies() const;
		int getDamage() const;
	};





	class Human : public Creature {
	public:
		Human();
		Human(int newStrength, int newHitpoints);
		std::string getSpecies() const;
		int getDamage() const;
	};





	class Elf : public Creature {
	public:
		Elf();
		Elf(int newStrength, int newHitpoints);
		std::string getSpecies() const;
		int getDamage() const;
	};





	class Demon : public Creature {
	public:
		Demon();
		Demon(int newStrength, int newHitpoints);
		std::string getSpecies() const;
		int getDamage() const;
	};





	class Cyberdemon : public Demon {
	public:
		Cyberdemon();
		Cyberdemon(int newStrength, int newHitpoints);
		std::string getSpecies() const;
		int getDamage() const;
	};





	class Balrog : public Demon {
	public:
		Balrog();
		Balrog(int newStrength, int newHitpoints);
		std::string getSpecies() const;
		int getDamage() const;
	};
}