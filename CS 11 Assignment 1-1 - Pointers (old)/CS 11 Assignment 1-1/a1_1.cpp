////////////////////////////////////////////////////////////////
//Max vonBlankenburg - CS 11 - 1/18/18 - Dave Harden - a1-1.cpp
// A collection of simple tasks using pointers
////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
using namespace std;

void noNegatives(int*);
void swap(int*, int*);

const int SIZE = 2;

int main() {
	int x;
	int y;
	int* p1;

	p1 = &x;
	*p1 = 99;
	cout << x << endl;
	cout << *p1 << endl;
	p1 = &y;
	*p1 = -300;

	int temp;
	int* p2; 
	p2 = &x;
	temp = *p2;
	*p2 = *p1; 
	*p1 = temp;
	noNegatives(&x);
	noNegatives(&y);
	p2 = &x;
	cout << "\nx is: " << *p2 << endl;
	p2 = &y;
	cout << "y is: " << *p2 << endl;

	int a[SIZE];
	p2 = a;
	*p2 = x;
	p2[1] = y;
	cout << "\nthe address of a[0] is: " << p2 << endl;
	cout << "the address of a[1] is: " << &p2[1] << endl;

	p1 = a;
	p2 = &a[1];
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	cout << "\na[0] is: " <<  a[0] << endl;
	cout << "a[1] is: " << a[1] << endl;

	swap(&x, &y);
	cout << "\nx is: " << x << endl;
	cout << "y is: " << y << endl;

	swap(a, &a[1]);
	cout << "\na[0] is: " << a[0] << endl;
	cout << "a[1] is: " << a[1] << endl;

	system("PAUSE");
	return 0;
}

//Accepts the address of an int variable, stored in x, and sets the int's value to 0 if it is negative
void noNegatives(int *x) {
	if (*x < 0)
		*x = 0;
}

//Accepts addresses from two int variables, stored in x and y, and swaps the contents of the two integers
void swap(int *x, int *y) {
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/*
99
99

x is : 0
y is : 99

the address of a[0] is : 00EFF920
the address of a[1] is : 00EFF924

a[0] is : 99
a[1] is : 0

x is : 99
y is : 0

a[0] is : 0
a[1] is : 99
Press any key to continue . . .*/