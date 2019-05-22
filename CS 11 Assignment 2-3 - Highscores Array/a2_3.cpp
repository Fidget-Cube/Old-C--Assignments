//***********************************************************//
// Max vonBlankenburg, CS 11, 1/31/18, Dave Harden, a2_3.cpp //
// This program accepts scores from a user for a fictitious  //
// game, sorts them, and displays them in descending order.  //
// It starts by asking the user for the amount of scores     //
// wanted, then uses that value to allocate a dynamic array  //
// of "highscore" objects, in which each element contains a  //
// "name" and a "score". It then runs three functions that   //
// obtain from the user each name and corresponding score,   //
// sort the scores along with their names in descending      //
// order, and display them in that order.                    //
//***********************************************************//
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int SIZE = 24;

struct highscore {
	int score;
	char name[SIZE];
};

void initializeArrays(highscore[], int);
void sortData(highscore[], int);
void displayData(const highscore[], int);

int main() {
	int arraySize;

	cout << "How many scores will you enter?: ";
	cin >> arraySize;
	highscore* scores = new highscore[arraySize];

	initializeArrays(scores, arraySize);
	sortData(scores, arraySize);
	displayData(scores, arraySize);

	system("PAUSE");
	return 0;
}

// This function asks the user for a score and a name associated with it for
// each element of the array, then stores those values in their respective 
// object variables.
void initializeArrays(highscore scores[], int size) {
	for (int x = 0; x < size; x++) {
		cout << "Enter the name for score #" << x + 1 << ": ";
		cin >> scores[x].name;
		cout << "Enter the score for score #" << x + 1 << ": ";
		cin >> scores[x].score;
	}
}

// This function does a selection sort on the values in the "score" variable of the array.
// For each element of the array besides the first, it compares said element
// to the one before it, and switches the values in each if said element is larger.
// The function continues with a while loop until no more switches are performed.
void sortData(highscore scores[], int size) {
	int switches = 0;

	do {
		switches = 0;

		for (int x = 1; x < size; x++) {
			if (scores[x].score > scores[x - 1].score) {
				swap(scores[x], scores[x - 1]);
				switches++;
			}
		}
	} while (switches > 0);
}

// This function displays the name and respective score of each array element in descending order.
void displayData(const highscore scores[], int size) {
	cout << "\nTop Scorers:" << endl;
	for (int x = 0; x < size; x++) {
		cout << scores[x].name << ": " << scores[x].score << endl;
	}
}

/*
How many scores will you enter?: 4
Enter the name for score #1: Suzy
Enter the score for score #1: 600
Enter the name for score #2: Kim
Enter the score for score #2: 9900
Enter the name for score #3: Armando
Enter the score for score #3: 8000
Enter the name for score #4: Tim
Enter the score for score #4: 514

Top Scorers:
Kim: 9900
Armando: 8000
Suzy: 600
Tim: 514
Press any key to continue . . .*/