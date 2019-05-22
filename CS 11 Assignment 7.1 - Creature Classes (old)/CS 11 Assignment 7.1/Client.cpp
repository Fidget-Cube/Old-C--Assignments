//=================================================//
// Max vonBlankenburg, CS 11, Harden, 3/8/18, a7.1 //
//=================================================//
#include "creature.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace cs_creature;

int main() {
	srand(time(0));

	Human h1;
	Elf e1;
	Cyberdemon c1;
	Balrog b1;

	Human h(20, 30);
	Elf e(40, 50);
	Cyberdemon c(60, 70);
	Balrog b(80, 90);


	cout << "default Human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
	cout << "default Elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
	cout << "default Cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
	cout << "default Balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
	cout << "non-default Human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
	cout << "non-default Elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
	cout << "non-default Cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
	cout << "non-default Balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
	cout << endl << endl;

	cout << "Examples of " << h.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++) {
		int damage = h.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;



	cout << "Examples of " << e.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++) {
		int damage = e.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;



	cout << "Examples of " << c.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++) {
		int damage = c.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;



	cout << "Examples of " << b.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++) {
		int damage = b.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;

	system("PAUSE");
	return 0;
}

/*
default Human strength/hitpoints: 10/10
default Elf strength/hitpoints: 10/10
default Cyberdemon strength/hitpoints: 10/10
default Balrog strength/hitpoints: 10/10
non-default Human strength/hitpoints: 20/30
non-default Elf strength/hitpoints: 40/50
non-default Cyberdemon strength/hitpoints: 60/70
non-default Balrog strength/hitpoints: 80/90


Examples of Human damage:
The Human attacks for 5 points!
Total damage = 5

The Human attacks for 1 points!
Total damage = 1

The Human attacks for 2 points!
Total damage = 2

The Human attacks for 8 points!
Total damage = 8

The Human attacks for 17 points!
Total damage = 17

The Human attacks for 1 points!
Total damage = 1

The Human attacks for 2 points!
Total damage = 2

The Human attacks for 8 points!
Total damage = 8

The Human attacks for 6 points!
Total damage = 6

The Human attacks for 18 points!
Total damage = 18


Examples of Elf damage:
The Elf attacks for 27 points!
Total damage = 27

The Elf attacks for 20 points!
Magical attack deals 20 additional damage!
Total damage = 40

The Elf attacks for 2 points!
Magical attack deals 2 additional damage!
Total damage = 4

The Elf attacks for 16 points!
Magical attack deals 16 additional damage!
Total damage = 32

The Elf attacks for 40 points!
Total damage = 40

The Elf attacks for 21 points!
Total damage = 21

The Elf attacks for 3 points!
Total damage = 3

The Elf attacks for 39 points!
Magical attack deals 39 additional damage!
Total damage = 78

The Elf attacks for 16 points!
Magical attack deals 16 additional damage!
Total damage = 32

The Elf attacks for 11 points!
Total damage = 11


Examples of Cyberdemon damage:
The Cyberdemon attacks for 48 points!
Total damage = 48

The Cyberdemon attacks for 43 points!
Total damage = 43

The Cyberdemon attacks for 5 points!
Total damage = 5

The Cyberdemon attacks for 43 points!
Total damage = 43

The Cyberdemon attacks for 20 points!
Total damage = 20

The Cyberdemon attacks for 29 points!
Total damage = 29

The Cyberdemon attacks for 37 points!
Total damage = 37

The Cyberdemon attacks for 60 points!
Total damage = 60

The Cyberdemon attacks for 31 points!
Total damage = 31

The Cyberdemon attacks for 3 points!
Demonic attack inflicts 50 additional damage!
Total damage = 53


Examples of Balrog damage:
Balrog attacks for 40 points!
Balrog speed attack deals 72 additional damage!
Total damage = 112

Balrog attacks for 54 points!
Balrog speed attack deals 67 additional damage!
Total damage = 121

Balrog attacks for 51 points!
Balrog speed attack deals 36 additional damage!
Total damage = 87

Balrog attacks for 33 points!
Demonic attack inflicts 50 additional damage!
Balrog speed attack deals 14 additional damage!
Total damage = 97

Balrog attacks for 75 points!
Balrog speed attack deals 72 additional damage!
Total damage = 147

Balrog attacks for 24 points!
Demonic attack inflicts 50 additional damage!
Balrog speed attack deals 31 additional damage!
Total damage = 105

Balrog attacks for 21 points!
Balrog speed attack deals 64 additional damage!
Total damage = 85

Balrog attacks for 56 points!
Balrog speed attack deals 48 additional damage!
Total damage = 104

Balrog attacks for 22 points!
Demonic attack inflicts 50 additional damage!
Balrog speed attack deals 10 additional damage!
Total damage = 82

Balrog attacks for 34 points!
Balrog speed attack deals 7 additional damage!
Total damage = 41


Press any key to continue . . .*/