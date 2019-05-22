#include "creature.h"
#include <iostream>
using namespace std;

namespace cs_creature {
	Creature::Creature() {
		strength = 10;
		hitpoints = 10;
	}





	Creature::Creature(int newStrength, int newHitpoints) {
		strength = newStrength;
		hitpoints = newHitpoints;
	}





	int Creature::getStrength() const {
		return strength;
	}





	int Creature::getHitpoints() const {
		return hitpoints;
	}





	void Creature::setStrength(int newStrength) {
		strength = newStrength;
	}





	void Creature::setHitpoints(int newHitpoints) {
		hitpoints = newHitpoints;
	}





	string Creature::getSpecies() const {
		return "Creature";
	}





	int Creature::getDamage() const {
		int damage;
		damage = (rand() % strength) + 1;
		return damage;
	}





	Human::Human() {
		setStrength(10);
		setHitpoints(10);
	}





	Human::Human(int newStrength, int newHitpoints) {
		setStrength(newStrength);
		setHitpoints(newHitpoints);
	}





	string Human::getSpecies() const {
		return "Human";
	}





	int Human::getDamage() const {
		int damage = Creature::getDamage();
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
		return damage;
	}





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
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
		if ((rand() % 2) == 0) {
			cout << "Magical attack deals " << damage << " additional damage!" << endl;
			damage *= 2;
		}
		return damage;
	}





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
		cout << " attacks for " << damage << " points!" << endl;
		if ((rand() % 4) == 0) {
			damage += 50;
			cout << "Demonic attack inflicts 50 additional damage!" << endl;
		}
		return damage;
	}





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





	int Cyberdemon::getDamage() const {
		cout << "The " << getSpecies();
		return Demon::getDamage();
	}





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
		cout << getSpecies();
		int damage = Demon::getDamage();
		int damage2 = (rand() % getStrength()) + 1;
		cout << "Balrog speed attack deals " << damage2 << " additional damage!" << endl;
		return damage += damage2;
	}
}