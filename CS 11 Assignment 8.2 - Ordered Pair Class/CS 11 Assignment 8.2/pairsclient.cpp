#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "orderedpair.h"
using namespace std;
using namespace cs_pairs;

void intPairTest(OrderedPair<int> myList[]);
void stringPairTest(OrderedPair<string> myList[]);


int main() {
	OrderedPair<int> intList[10];
	OrderedPair<string> stringList[10];

	srand(static_cast<unsigned>(time(0)));
	
	intPairTest(intList);
	stringPairTest(stringList);

	system("PAUSE");
}





void intPairTest(OrderedPair<int> myList[]) {
	int num1, num2;

	cout << "default value: ";
	myList[0].print();
	cout << endl;

	for (int i = 0; i < 10; i++) {
		myList[i].setFirst(rand() % 50);
		myList[i].setSecond(rand() % 50 + 50);
	}

	myList[2] = myList[0] + myList[1];

	if (myList[0] < myList[1]) {
		myList[0].print();
		cout << " is less than ";
		myList[1].print();
		cout << endl;
	}

	for (int i = 0; i < 10; i++) {
		myList[i].print();
		cout << endl;
	}

	cout << "Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: ";
	cin >> num1 >> num2;
	OrderedPair<int> x;

	try {
		x.setFirst(num1);
		x.setSecond(num2);
	}
	catch (OrderedPair<int>::DuplicateMemberError e) {
		x.setFirst(0);
		x.setSecond(0);
	}

	cout << "The resulting OrderedPair: ";
	x.print();
	cout << endl;
}





void stringPairTest(OrderedPair<string> myList[]) {
	string string1, string2;

	cout << "default value: ";
	myList[0].print();
	cout << endl;

	for (int i = 0; i < 10; i++) {
		string empty = "";
		myList[i].setFirst(empty + char('a' + rand() % 26));
		myList[i].setSecond(empty + char('A' + rand() % 26));
	}

	myList[2] = myList[0] + myList[1];

	if (myList[0] < myList[1]) {
		myList[0].print();
		cout << " is less than ";
		myList[1].print();
		cout << endl;
	}

	for (int i = 0; i < 10; i++) {
		myList[i].print();
		cout << endl;
	}

	cout << "Enter two strings to use in an OrderedPair.  Make sure they are different strings: ";
	cin >> string1 >> string2;
	OrderedPair<string> x;

	try {
		x.setFirst(string1);
		x.setSecond(string2);
	}
	catch (OrderedPair<string>::DuplicateMemberError e) {
		x.setFirst("");
		x.setSecond("");
	}

	cout << "The resulting OrderedPair: ";
	x.print();
	cout << endl;
}

/*
default value: (0, 0)
(42, 89)
(31, 79)
(73, 168)
(22, 61)
(21, 85)
(29, 78)
(47, 99)
(49, 86)
(46, 79)
(3, 78)
Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: 4 4
The resulting OrderedPair: (0, 0)
default value: (, )
(l, W)
(i, J)
(li, WJ)
(y, C)
(t, T)
(o, O)
(n, S)
(t, Z)
(i, F)
(m, B)
Enter two strings to use in an OrderedPair.  Make sure they are different strings: four four
The resulting OrderedPair: (, )
Press any key to continue . . .*/