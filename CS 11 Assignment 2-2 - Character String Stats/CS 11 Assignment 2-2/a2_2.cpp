//******************************************************//
// Max vonBlankenburg, CS 11, Harden, 1/30/18, a2_2.cpp //
// This program creates an array of struct datatypes    //
// named "charOccurrences" that each have two values, a //
// char to hold a letter and an int to hold the number  //
// of times that letter occurs. The user is then asked  //
// to enter text, ending with a period, which the input //
// stream checks character by character, assigning and  //
// incrementing the corresponding array elements.       //
// Finally, the program sorts the array in descending   //
// order, and displays it as a frequency table.         //
//******************************************************//
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct charOccurrences {
	char letter = '\0';
	int occurrences = 0;
};

void sortArray(charOccurrences[]);
void displayArray(const charOccurrences[]);

const int SIZE = 26;

// "charOccurrences" object variables will always be initialized to 0 or '\0'.
int main() {
	charOccurrences characters[SIZE];
	char input = '\0';

	cout << "Enter a bunch of text. When finished, enter a period \'.\':" << endl;
	while (input != '.') {
		cin >> input;
		if (isalpha(input))
			characters[tolower(input) - 'a'].letter = tolower(input);
			characters[tolower(input) - 'a'].occurrences++;
	}

	sortArray(characters);
	displayArray(characters);

	system("PAUSE");
	return 0;
}


// Takes an array of the "charOccurrences" datatype and performs 
// a selection sort, sorting the array in descending order.
void sortArray(charOccurrences array[]) {
	int numSwaps;
	do {
		numSwaps = 0;

		for (int x = 1; x <= ('z' - 'a'); x++) {
			if (array[x].occurrences > array[x - 1].occurrences) {
				swap(array[x], array[x - 1]);
				numSwaps++;
			}
		}
	} while (numSwaps != 0);
}

// Takes an array of datatype "charOccurrences" and displays 
// a table sorted in descending order by number of
// occurrences, showing the letter next to the amount of
// times it occurred.
void displayArray(const charOccurrences array[]) {
	cout << "Letter:" << setw(26) << "Number of Occurrences:" << endl;
	for (int x = 0; x < ('z' - 'a'); x++) {
		if (array[x].occurrences != 0)
			cout << setw(7) << array[x].letter << setw(5) << array[x].occurrences << endl;
	}
}

/*
Enter a bunch of text. When finished, enter a period '.':
do be Do Bo. xyz
Letter:    Number of Occurrences:
	  o    3
	  b    2
	  d    2
	  e    1
Press any key to continue . . .*/