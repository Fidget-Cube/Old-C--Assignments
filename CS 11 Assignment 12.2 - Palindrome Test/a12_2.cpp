//===================================================//
// Max vonBlankenburg, CS 11, Harden, 4/17/18, a12_2 //
//===================================================//
// This program accepts a string of characters from  //
// the user and determines whether or not the string //
// is a palindrome.                                  //
//===================================================//
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "mystring.h"
using namespace std;
using namespace cs_mystring;

bool isAPalindrome(const MyString& string, int start, int end);

int main() {
	MyString input;

	cout << "Hello there fellow fleshy Human!" << endl;
	cout << "Feel free to enter a string, I'll tell you if it's a palindrome." << endl;
	cout << "(Type \"quit\" to quit)" << endl << endl;
	cout << "Enter a string: ";
	input.read(cin, '\n');
	while (input != "quit") {
		if (isAPalindrome(input, 0, input.length() - 1)) {
			cout << input << " is a palindrome." << endl;
		}
		else {
			cout << input << " is not a palindrome." << endl;
		}
		cout << "Enter a string: ";
		input.read(cin, '\n');
	}

	system("pause");
}





// This recursive function returns true if string is a palindrome,
// false otherwise. It starts by moving start and end indexes off of 
// any punctuation or whitespace chars, and checks to see if the string
// is empty, returning true if so. It then compares the string elements
// at start and end to see if they are the same, while also calling 
// isAPalindrome with start one greater and end one lesser; The function
// returns true if both these conditions are true, false otherwise.
bool isAPalindrome(const MyString& string, int start, int end) {
	while (start <= end && (ispunct(string[start]) || isspace(string[start]))) {
		start++;
	}
	while (start <= end && (ispunct(string[end]) || isspace(string[end]))) {
		end--;
	}
	if (start < end) {
		if (tolower(string[start]) == tolower(string[end]) && isAPalindrome(string, start + 1, end - 1)) {
			return true;
		}
		return false;
	}
	return true;
}





/*
Hello there fellow fleshy Human!
Feel free to enter a string, I'll tell you if it's a palindrome.
(Type "quit" to quit)

Enter a string:
is a palindrome.
Enter a string: ;
; is a palindrome.
Enter a string: ;;
;; is a palindrome.
Enter a string: Able was I, ere I saw Elba.
Able was I, ere I saw Elba. is a palindrome.
Enter a string: peanut butter
peanut butter is not a palindrome.
Enter a string: swishes
swishes is not a palindrome.
Enter a string: Are we not pure? "No, sir!" Panama's moody Noriega brags. "It is garbage!" Irony dooms a man-a prisoner up to new era.
Are we not pure? "No, sir!" Panama's moody Noriega brags. "It is garbage!" Irony dooms a man-a prisoner up to new era. is a palindrome.
Enter a string: quit
Press any key to continue . . .*/