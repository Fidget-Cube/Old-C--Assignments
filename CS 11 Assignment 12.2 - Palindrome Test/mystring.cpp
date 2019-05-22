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
		return (strcmp(stringy1.stringData, stringy2.stringData) == 0);
	}





	bool operator!=(const MyString &stringy1, const MyString &stringy2) {
		return (strcmp(stringy1.stringData, stringy2.stringData) != 0);
	}
}