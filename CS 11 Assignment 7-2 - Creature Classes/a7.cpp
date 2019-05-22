//=================================================//
// Max vonBlankenburg, CS 11, Harden, 3/8/18, a7.2 //
//=================================================//
#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include "balrog.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;
using namespace cs_creature;

void battleArena(Creature &Creature1, Creature &Creature2);

int main() {
	srand((time(0)));

	Human Griffith(20, 30);
	Elf Larrus(30, 20);
	Cyberdemon Fjonir(20, 40);
	Balrog Rylarth(40, 50);

	battleArena(Griffith, Larrus);
	battleArena(Fjonir, Rylarth);
	battleArena(Larrus, Fjonir);
	battleArena(Griffith, Rylarth);

	system("PAUSE");
	return 0;
}



// pre: battleArena takes two Creature objects, "Creature1" and "Creature2", as parameters.
// post: A battle is simulated by calling the getDamage function for each creature and
//       subtracting the result from the opponent's hitpoints variable. The match is decided
//       when one or both of the Creature objects' hitpoints variable drops to or below 0.
void battleArena(Creature &Creature1, Creature &Creature2) {
	int startHealth1 = Creature1.getHitpoints();
	int startHealth2 = Creature2.getHitpoints();
	bool fighting = true;
	while (fighting) {
		int damage1 = Creature1.getDamage();
		Creature2.setHitpoints(Creature2.getHitpoints() - damage1);
		cout << "Total damage: " << damage1 << ", opponent at " << Creature2.getHitpoints() << " health!" << endl;
		int damage2 = Creature2.getDamage();
		Creature1.setHitpoints(Creature1.getHitpoints() - damage2);
		cout << "Total damage: " << damage2 << ", opponent at " << Creature1.getHitpoints() << " health!" << endl;

		if (Creature1.getHitpoints() <= 0 && Creature2.getHitpoints() <= 0) {
			cout << "The opponents cannot continue fighting, we have a Tie!" << endl << endl;
			fighting = false;
			Creature1.setHitpoints(startHealth1);
			Creature2.setHitpoints(startHealth2);
		}
		else if (Creature1.getHitpoints() <= 0) {
			cout << "The " << Creature1.getSpecies() << " has been defeated! The " << Creature2.getSpecies() << " Wins!" << endl << endl;
			fighting = false;
			Creature1.setHitpoints(startHealth1);
			Creature2.setHitpoints(startHealth2);
		}
		else if (Creature2.getHitpoints() <= 0) {
			cout << "The " << Creature2.getSpecies() << " has been defeated! The " << Creature1.getSpecies() << " Wins!" << endl << endl;
			fighting = false;
			Creature1.setHitpoints(startHealth1);
			Creature2.setHitpoints(startHealth2);
		}
	}
}

/*
The Human attacks for 19 points!
Total damage: 19, opponent at 1 health!
The Elf attacks for 8 points!
Magical attack deals 8 additional damage!
Total damage: 16, opponent at 14 health!
The Human attacks for 9 points!
Total damage: 9, opponent at -8 health!
The Elf attacks for 2 points!
Magical attack deals 2 additional damage!
Total damage: 4, opponent at 10 health!
The Elf has been defeated! The Human Wins!

The Cyberdemon attacks for 17 points!
Demonic attack inflicts 50 additional damage!
Total damage: 67, opponent at -17 health!
The Balrog attacks for 25 points!
Balrog speed attack deals 31 additional damage!
Total damage: 56, opponent at -16 health!
The opponents cannot continue fighting, we have a Tie!

The Elf attacks for 27 points!
Magical attack deals 27 additional damage!
Total damage: 54, opponent at -14 health!
The Cyberdemon attacks for 2 points!
Demonic attack inflicts 50 additional damage!
Total damage: 52, opponent at -32 health!
The opponents cannot continue fighting, we have a Tie!

The Human attacks for 20 points!
Total damage: 20, opponent at 30 health!
The Balrog attacks for 4 points!
Balrog speed attack deals 30 additional damage!
Total damage: 34, opponent at -4 health!
The Human has been defeated! The Balrog Wins!

Press any key to continue . . .*/