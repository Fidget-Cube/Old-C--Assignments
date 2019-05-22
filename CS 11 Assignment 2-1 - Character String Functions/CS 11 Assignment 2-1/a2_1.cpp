//******************************************************//
// Max vonBlankenburg, CS 11, Harden, 1/25/18, a2_1.cpp //
// A collection of functions implementing null          //
// terminated c-style strings.                          //
//******************************************************//
#include <iostream>
#include <cstring>
#include <cstdlib>
using std::cout;
using std::endl;

int lastIndexOf(const char*, char);
void reverse(char*);
int replace(char*, char, char);
bool isPalindrome(const char*);
void toupper(char*);
int numLetters(const char*);

//Main function used strictly for testing functions.
int main() {
    char sample1[] = "Hello There!";
    char target = 'l';
    cout << lastIndexOf(sample1, target) << endl;
    target = 'S';
    cout << lastIndexOf(sample1, target) << endl << endl;

    reverse(sample1);
    cout << sample1 << endl;
    reverse(sample1);
    cout << sample1 << endl << endl;

    cout << replace(sample1, 'e', 'u') << " change(s) were made: " << sample1 << endl;
    cout << replace(sample1, 'l', '*') << " change(s) were made: " << sample1 << endl << endl;

    if (isPalindrome(sample1))
        cout << '"' << sample1 << "\" is a palindrome." << endl;
    else
        cout << '"' << sample1 << "\" is not a palindrome." << endl;
    char sample2[] = "GoHangASalami;ImALasagnaHog";
    if (isPalindrome(sample2))
        cout << '"' << sample2 << "\" is a palindrome." << endl << endl;
    else
        cout << '"' << sample2 << "\" is not a palindrome." << endl << endl;

    toupper(sample1);
    cout << sample1 << endl << endl;

    cout << "There are " << numLetters(sample1) << " letters in " << sample1 << endl;
    cout << "There are " << numLetters(sample2) << " letters in " << sample2 << endl;

    system("PAUSE");
	return 0;
}

//This function takes two arguments, a single char and a c-string,
//and returns the last index that the char can be found in the c-string.
//If the char is not found, function returns -1.
int lastIndexOf(const char* inString, char target) {
	int index = -1;
	for (int i = 0; inString[i] != '\0'; i++) {
		if (inString[i] == target)
			index = i;
	}
	return index;
}

//This function takes a c-string as an argument and reverses it.
//It doesn't do this by creating another string, but by swapping
//the first and last characters of the string parameter, then
//second and second-to-last, and so on.
void reverse(char* inString) {
    char temp;
    for (int i = 0; i < (strlen(inString) / 2); i++) {
        temp = inString[i];                               //
		inString[i] = inString[strlen(inString) - 1 - i]; // Can be replaced with swap() function
		inString[strlen(inString) - 1 -i] = temp;         //
    }
}

//This function finds all instances of a char "target" in a c-string
//and replaces them with char "replacementChar".
int replace(char* inString, char target, char replacementChar) {
    int targetCounter = 0;
    for (int i = 0; inString[i] != '\0'; i++) {
        if (inString[i] == target) {
            inString[i] = replacementChar;
            targetCounter++;
        }
    }
    return targetCounter;
}

//This function takes a c-string as an argument and returns true
//or false depending on if the string is a palindrome. It does this
//by checking each character with the one on the opposite end of the string.
bool isPalindrome(const char* inString) {
    for (int i = 0; inString[i] != '\0'; i++) {
        if (tolower(inString[i]) != tolower(inString[strlen(inString) - 1 - i]))
            return false;
    }
    return true;
}

//This function takes a c-string as an argument and converts all its
//letters to uppercase.
void toupper(char* inString) {
    for (int i = 0; inString[i] != '\0'; i++) {
		if (islower(inString[i])) {
			inString[i] -= 32;
		}
    }
}

//This function takes a c-string as an argument and returns
//the number of letters in the string.
int numLetters(const char* inString) {
    int letterCounter = 0;
    for (int i = 0; inString[i] != '\0'; i++) {
        if (isalpha(inString[i]))
            letterCounter++;
    }
    return letterCounter;
}


/*
3
-1

!erehT olleH
Hello There!

3 change(s) were made: Hullo Thuru!
2 change(s) were made: Hu**o Thuru!

"Hu**o Thuru!" is not a palindrome.
"GoHangASalami;ImALasagnaHog" is a palindrome.

HU**O THURU!

There are 8 letters in HU**O THURU!
There are 26 letters in GoHangASalami;ImALasagnaHog
Press any key to continue . . .*/
