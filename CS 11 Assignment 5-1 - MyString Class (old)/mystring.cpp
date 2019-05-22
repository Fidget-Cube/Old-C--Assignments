/*
~implementation comment goes here~*/
#pragma warning(disable:4996)
#include "mystring.h"
#include <iostream>
#include <cassert>
using namespace std;

namespace cs_mystring {
	MyString::MyString() {
		stringData = new char[1];
	}






	MyString::MyString(const char stringy[]) {
		int length = strlen(stringy);
		stringData = new char[length + 1];
		strcpy(stringData, stringy);
	}





	void MyString::operator=(const MyString &stringy) {
		if (*this != stringy) {
			int length = stringy.length();
			delete[] stringData;
			stringData = new char[length + 1];
			strcpy(stringData, stringy.stringData);
		}
	}





	MyString::MyString(const MyString &stringy) {
		int length = stringy.length();
		stringData = new char[length + 1];
		strcpy(stringData, stringy.stringData);
	}





	MyString::~MyString() {
		delete[] stringData;
	}





	int MyString::length() const {
		return strlen(stringData);
	}





	ostream &operator << (ostream &out, const MyString &stringy) {
		return out << stringy.stringData;
	}





	char MyString::operator[](int index) const {
		assert(index >= 0 && index <= strlen(stringData) - 1);
		return stringData[index];
	}





	char& MyString::operator[](int index) {
		assert(index >= 0 && index <= strlen(stringData) - 1);
		return stringData[index];
	}




	
	bool operator<(const MyString &stringy1, const MyString &stringy2) {
		return (strcmp(stringy1.stringData, stringy2.stringData) < 0);
	}





	bool operator<=(const MyString &stringy1, const MyString &stringy2) {
		return (strcmp(stringy1.stringData, stringy2.stringData) <= 0);
	}





	bool operator>(const MyString &stringy1, const MyString &stringy2) {
		return (strcmp(stringy1.stringData, stringy2.stringData) > 0);
	}





	bool operator>=(const MyString &stringy1, const MyString &stringy2) {
		return (strcmp(stringy1.stringData, stringy2.stringData) >= 0);
	}





	bool operator==(const MyString &stringy1, const MyString &stringy2) {
		return (!strcmp(stringy1.stringData, stringy2.stringData));
	}





	bool operator!=(const MyString &stringy1, const MyString &stringy2) {
		return (strcmp(stringy1.stringData, stringy2.stringData));
	}
}

/*
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing apple to
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing  to Banana
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing Banana to Banana
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing why to wackity
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky
Press any key to continue . . .*/