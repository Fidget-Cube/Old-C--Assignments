//===================================================//
// Max vonBlankenburg, CS 11, Harden, 4/17/18, a12_1 //
//===================================================//
// This program is used to test a recursive function. //
// It creates a c-string and prints it, then reverses //
// the order of a few words and prints the results,   //
// then finishes off by reversing the whole c-string  //
// and printing it.                                   //
//===================================================//
#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 47;

void reverseWithinBounds(char array[], int start, int end);
void reverseCstring(char array[]);

int main() {
	char array[SIZE] = "My favorite color is soup.";
	
	cout << array << endl;
	reverseWithinBounds(array, 12, 16);
	cout << array << endl;
	reverseWithinBounds(array, 3, 10);
	cout << array << endl;
	reverseWithinBounds(array, 21, 24);
	cout << array << endl << endl;

	reverseCstring(array);
	cout << array << endl;

	system("pause");
}





// This recursive function takes a c-string (array) and two ints 
// (start and end) as parameters, and reverses the order of characters 
// within array between the indexes of start and end, including the 
// characters at the indexes.
void reverseWithinBounds(char array[], int start, int end) {
	if (start <= end) {
		swap(array[start], array[end]);
		reverseWithinBounds(array, start + 1, end - 1);
	}
}





// This function takes array as its argument and reverses the order
// of the characters in array.
void reverseCstring(char array[]) {
	reverseWithinBounds(array, 0, strlen(array) - 1);
}





/*
My favorite color is soup.
My favorite roloc is soup.
My etirovaf roloc is soup.
My etirovaf roloc is puos.

.soup si color favorite yM
Press any key to continue . . .*/