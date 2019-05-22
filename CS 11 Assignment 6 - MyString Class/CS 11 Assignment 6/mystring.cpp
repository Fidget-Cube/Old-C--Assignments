/*
"stringData" is a character pointer used
to hold character arrays, or, in other words,
a c-string data member.

stringData is initialized to "" by default
and its data is deallocated upon destruction.

stringData will always be allocated with
just enough space to hold its characters.

Extraction functions will take no more than
127 characters.*/
#pragma warning(disable:4996)
#include "mystring.h"
#include <iostream>
#include <cassert>
using namespace std;

namespace cs_mystring {

	const int LIMIT = 128;

	MyString::MyString() {
		stringData = new char[1]{ "" };
	}


	



	MyString::MyString(const char stringy[]) {
		stringData = new char[strlen(stringy) + 1];
		strcpy(stringData, stringy);
	}





	MyString MyString::operator=(const MyString &stringy) {
		if (this != &stringy) {
			delete[] stringData;
			stringData = new char[stringy.length() + 1];
			strcpy(stringData, stringy.stringData);
		}
		return *this;
	}





	MyString::MyString(const MyString &stringy) {
		stringData = new char[stringy.length() + 1];
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




	
	istream &operator >> (istream &in, MyString &stringy) {
		char container[LIMIT];
		in >> container;
		delete[] stringy.stringData;
		stringy.stringData = new char[strlen(container) + 1];
		strcpy(stringy.stringData, container);
		return in;
	}
	



	
	void MyString::read(istream &in, char delimiter) {
		char container[LIMIT];
		in.getline(container, LIMIT, delimiter);
		delete[] stringData;
		stringData = new char[strlen(container) + 1];
		strcpy(stringData, container);
	}
	




	char MyString::operator[](int index) const {
		assert(index >= 0 && index <= strlen(stringData) - 1);
		return stringData[index];
	}





	char& MyString::operator[](int index) {
		assert(index >= 0 && index <= strlen(stringData) - 1);
		return stringData[index];
	}




	
	MyString operator+(const MyString &stringy1, const MyString &stringy2) {
		MyString returner;
		delete[] returner.stringData;
		returner.stringData = new char[stringy1.length() + stringy2.length() + 1];
		strcpy(returner.stringData, stringy1.stringData);
		strcat(returner.stringData, stringy2.stringData);
		return returner;
	}
	



	
	MyString MyString::operator+=(const MyString &stringy) {
		*this = *this + stringy;
		return *this;
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




/*----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

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
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo
Press any key to continue . . .*/