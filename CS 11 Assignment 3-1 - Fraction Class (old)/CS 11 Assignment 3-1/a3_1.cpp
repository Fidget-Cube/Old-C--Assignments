//*****************************************************//
// Max vonBlankenburg, CS 11, Harden, 2/6/18, a3_1.cpp //
//
//*****************************************************//
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Fraction {
public:
	int numerator;
	int denominator;
public:
	Fraction(int, int);
	friend ostream &operator<<(ostream &, const Fraction &);
	friend bool operator < (const Fraction&, const Fraction&);
	friend bool operator <= (const Fraction&, const Fraction&);
	friend bool operator > (const Fraction&, const Fraction&);
	friend bool operator >= (const Fraction&, const Fraction&);
	friend bool operator == (const Fraction&, const Fraction&);
	friend bool operator != (const Fraction&, const Fraction&);
	friend Fraction operator + (Fraction, const Fraction&);
	friend Fraction operator - (Fraction, const Fraction&);
	friend Fraction operator * (Fraction, const Fraction&);
	friend Fraction operator / (Fraction, const Fraction&);
	Fraction operator += (const Fraction&);
	Fraction operator -= (const Fraction&);
	Fraction operator *= (const Fraction&);
	Fraction operator /= (const Fraction&);
	Fraction operator ++ ();
	Fraction operator ++ (int);
	Fraction operator -- ();
	Fraction operator -- (int);
};





// Constructor initializes the member functions "numerator" and "denominator"
// with values passed to the parameters "inNumerator" and "inDenominator." If
// no value is passed to either one, "inNumerator" defaults to 0 while "inDenominator"
// defaults to 1. "denominator" will never have a value of 0.
Fraction::Fraction(int inNumerator = 0, int inDenominator = 1) {
	numerator = inNumerator;
	if (!inDenominator)
		denominator = 1;
	else
		denominator = inDenominator;
}





// Function overloads the "<<" operator for objects of the "Fraction"
// class by taking an ostream parameter "stream" and a Fraction object
// parameter "fraction", running an ostream output, and returning "stream".
ostream &operator<<(ostream &stream, const Fraction &fraction) {
	return stream << fraction.numerator << '/' << fraction.denominator;
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then returns true if "left" is less than "right",
// false otherwise.
bool operator < (const Fraction &left, const Fraction &right) {
	return (left.numerator * right.denominator) < (right.numerator * left.denominator);
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then returns true if "left" is less than or equal
// to "right", false otherwise.
bool operator <= (const Fraction &left, const Fraction &right) {
	return (left.numerator * right.denominator) <= (right.numerator * left.denominator);
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then returns true if "left" is greater than "right",
// false otherwise.
bool operator > (const Fraction &left, const Fraction &right) {
	return (left.numerator * right.denominator) > (right.numerator * left.denominator);
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then returns true if "left" is greater than or
// equal to "right", false otherwise.
bool operator >= (const Fraction &left, const Fraction &right) {
	return (left.numerator * right.denominator) >= (right.numerator * left.denominator);
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then returns true if "left" is equal to "right",
// false otherwise.
bool operator == (const Fraction &left, const Fraction &right) {
	return (left.numerator * right.denominator) == (right.numerator * left.denominator);
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then returns true if "left" is not equal to "right",
// false otherwise.
bool operator != (const Fraction &left, const Fraction &right) {
	return (left.numerator * right.denominator) != (right.numerator * left.denominator);
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then adds the fractions together and returns
// the result.
Fraction operator + (Fraction left, const Fraction &right) {
	left.numerator = (left.numerator * right.denominator) + (right.numerator * left.denominator);
	left.denominator *= right.denominator;
	return left;
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then subtracts "right" from "left" and returns
// the result.
Fraction operator - (Fraction left, const Fraction &right) {
	left.numerator = (left.numerator * right.denominator) - (right.numerator * left.denominator);
	left.denominator *= right.denominator;
	return left;
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then multiplies the fractions together and returns
// the result.
Fraction operator * (Fraction left, const Fraction &right) {
	left.numerator *= right.numerator;
	left.denominator *= right.denominator;
	return left;
}





// Function takes two Fraction objects and assigns them to parameters
// "left" and "right", then divides "left" by "right" and returns
// the result.
Fraction operator / (Fraction left, const Fraction &right) {
	left.numerator *= right.denominator;
	left.denominator *= right.numerator;
	return left;
}





// Function takes one fraction object and assigns it to the "right"
// parameter, then assigns the fraction object calling the function
// to the sum of said function and "right". The calling object is
// also returned.
Fraction Fraction::operator += (const Fraction &right) {
	*this = *this + right;
	return *this;
}





// Function takes one fraction object and assigns it to the "right"
// parameter, then assigns the fraction object calling the function
// to the difference between said function and "right". The calling object is
// also returned.
Fraction Fraction::operator -= (const Fraction &right) {
	*this = *this - right;
	return *this;
}





// Function takes one fraction object and assigns it to the "right"
// parameter, then assigns the fraction object calling the function
// to the product of said function and "right". The calling object is
// also returned.
Fraction Fraction::operator *= (const Fraction &right) {
	*this = *this * right;
	return *this;
}





// Function takes one fraction object and assigns it to the "right"
// parameter, then assigns the fraction object calling the function
// to the quotient of said function and "right". The calling object is
// also returned.
Fraction Fraction::operator /= (const Fraction &right) {
	*this = *this / right;
	return *this;
}





// Function adds 1 to the fraction object calling it, then returns the result.
Fraction Fraction::operator ++ () {
	*this = *this + 1;
	return *this;
}




// Function adds 1 to the fraction object calling it, then returns
// the value of the object before it was incremented.
Fraction Fraction::operator ++ (int) {
	Fraction temp(*this);
	*this = *this + 1;
	return temp;
}





// Function subtracts 1 from the fraction object calling it, then returns the result.
Fraction Fraction::operator -- () {
	*this = *this - 1;
	return *this;
}





// Function subtracts 1 from the fraction object calling it, then returns
// the value of the object before it was decremented.
Fraction Fraction::operator -- (int) {
	Fraction temp(*this);
	*this = *this - 1;
	return temp;
}





void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
string boolString(bool convertMe);

int main()
{
	BasicTest();
	RelationTest();
	BinaryMathTest();
	MathAssignTest();

	system("PAUSE");
	return 0;
}





void BasicTest()
{
	cout << "\n----- Testing basic Fraction creation & printing\n";

	const Fraction fr[] = { Fraction(4, 8), Fraction(-15,21),
		Fraction(10), Fraction(12, -3),
		Fraction(), Fraction(28, 6), Fraction(0, 12) };

	for (int i = 0; i < 7; i++) {
		cout << "Fraction [" << i << "] = " << fr[i] << endl;
	}



}





string boolString(bool convertMe) {
	if (convertMe) {
		return "true";
	}
	else {
		return "false";
	}
}


void RelationTest()
{
	cout << "\n----- Testing relational operators between Fractions\n";

	const Fraction fr[] = { Fraction(3, 6), Fraction(1,2), Fraction(-15,30),
		Fraction(1,10), Fraction(0,1), Fraction(0,2) };

	for (int i = 0; i < 5; i++) {
		cout << "Comparing " << fr[i] << " to " << fr[i + 1] << endl;
		cout << "\tIs left < right? " << boolString(fr[i] < fr[i + 1]) << endl;
		cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i + 1]) << endl;
		cout << "\tIs left > right? " << boolString(fr[i] > fr[i + 1]) << endl;
		cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i + 1]) << endl;
		cout << "\tDoes left == right? " << boolString(fr[i] == fr[i + 1]) << endl;
		cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i + 1]) << endl;
	}

	cout << "\n----- Testing relations between Fractions and integers\n";
	Fraction f(-3, 6);
	int num = 2;
	cout << "Comparing " << f << " to " << num << endl;
	cout << "\tIs left < right? " << boolString(f < num) << endl;
	cout << "\tIs left <= right? " << boolString(f <= num) << endl;
	cout << "\tIs left > right? " << boolString(f > num) << endl;
	cout << "\tIs left >= right? " << boolString(f >= num) << endl;
	cout << "\tDoes left == right? " << boolString(f == num) << endl;
	cout << "\tDoes left != right ? " << boolString(f != num) << endl;

	Fraction g(1, 4);
	num = -3;
	cout << "Comparing " << num << " to " << g << endl;
	cout << "\tIs left < right? " << boolString(num < g) << endl;
	cout << "\tIs left <= right? " << boolString(num <= g) << endl;
	cout << "\tIs left > right? " << boolString(num > g) << endl;
	cout << "\tIs left >= right? " << boolString(num >= g) << endl;
	cout << "\tDoes left == right? " << boolString(num == g) << endl;
	cout << "\tDoes left != right ? " << boolString(num != g) << endl;
}





void BinaryMathTest()
{
	cout << "\n----- Testing binary arithmetic between Fractions\n";

	const Fraction fr[] = { Fraction(1, 6), Fraction(1,3),
		Fraction(-2,3), Fraction(5), Fraction(-4,3) };

	for (int i = 0; i < 4; i++) {
		cout << fr[i] << " + " << fr[i + 1] << " = " << fr[i] + fr[i + 1] << endl;
		cout << fr[i] << " - " << fr[i + 1] << " = " << fr[i] - fr[i + 1] << endl;
		cout << fr[i] << " * " << fr[i + 1] << " = " << fr[i] * fr[i + 1] << endl;
		cout << fr[i] << " / " << fr[i + 1] << " = " << fr[i] / fr[i + 1] << endl;
	}

	cout << "\n----- Testing arithmetic between Fractions and integers\n";
	Fraction f(-1, 2);
	int num = 4;
	cout << f << " + " << num << " = " << f + num << endl;
	cout << f << " - " << num << " = " << f - num << endl;
	cout << f << " * " << num << " = " << f * num << endl;
	cout << f << " / " << num << " = " << f / num << endl;

	Fraction g(-1, 2);
	num = 3;
	cout << num << " + " << g << " = " << num + g << endl;
	cout << num << " - " << g << " = " << num - g << endl;
	cout << num << " * " << g << " = " << num * g << endl;
	cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{
	cout << "\n----- Testing shorthand arithmetic assignment on Fractions\n";

	Fraction fr[] = { Fraction(1, 6), Fraction(4),
		Fraction(-1,2), Fraction(5) };

	for (int i = 0; i < 3; i++) {
		cout << fr[i] << " += " << fr[i + 1] << " = ";
		cout << (fr[i] += fr[i + 1]) << endl;
		cout << fr[i] << " -= " << fr[i + 1] << " = ";
		cout << (fr[i] -= fr[i + 1]) << endl;
		cout << fr[i] << " *= " << fr[i + 1] << " = ";
		cout << (fr[i] *= fr[i + 1]) << endl;
		cout << fr[i] << " /= " << fr[i + 1] << " = ";
		cout << (fr[i] /= fr[i + 1]) << endl;
	}

	cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
	Fraction f(-1, 3);
	int num = 3;
	cout << f << " += " << num << " = ";
	cout << (f += num) << endl;
	cout << f << " -= " << num << " = ";
	cout << (f -= num) << endl;
	cout << f << " *= " << num << " = ";
	cout << (f *= num) << endl;
	cout << f << " /= " << num << " = ";
	cout << (f /= num) << endl;

	cout << "\n----- Testing increment/decrement prefix and postfix\n";
	Fraction g(-1, 3);
	cout << "Now g = " << g << endl;
	cout << "g++ = " << g++ << endl;
	cout << "Now g = " << g << endl;
	cout << "++g = " << ++g << endl;
	cout << "Now g = " << g << endl;
	cout << "g-- = " << g-- << endl;
	cout << "Now g = " << g << endl;
	cout << "--g = " << --g << endl;
	cout << "Now g = " << g << endl;
}


/*
----- Testing basic Fraction creation & printing
Fraction [0] = 4/8
Fraction [1] = -15/21
Fraction [2] = 10/1
Fraction [3] = 12/-3
Fraction [4] = 0/1
Fraction [5] = 28/6
Fraction [6] = 0/12

----- Testing relational operators between Fractions
Comparing 3/6 to 1/2
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false
Comparing 1/2 to -15/30
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing -15/30 to 1/10
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing 1/10 to 0/1
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing 0/1 to 0/2
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -3/6 to 2
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing -3 to 1/4
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 9/18
1/6 - 1/3 = -3/18
1/6 * 1/3 = 1/18
1/6 / 1/3 = 3/6
1/3 + -2/3 = -3/9
1/3 - -2/3 = 9/9
1/3 * -2/3 = -2/9
1/3 / -2/3 = 3/-6
-2/3 + 5/1 = 13/3
-2/3 - 5/1 = -17/3
-2/3 * 5/1 = -10/3
-2/3 / 5/1 = -2/15
5/1 + -4/3 = 11/3
5/1 - -4/3 = 19/3
5/1 * -4/3 = -20/3
5/1 / -4/3 = 15/-4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 7/2
-1/2 - 4 = -9/2
-1/2 * 4 = -4/2
-1/2 / 4 = -1/8
3 + -1/2 = 5/2
3 - -1/2 = 7/2
3 * -1/2 = -3/2
3 / -1/2 = 6/-1

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4/1 = 25/6
25/6 -= 4/1 = 1/6
1/6 *= 4/1 = 4/6
4/6 /= 4/1 = 4/24
4/1 += -1/2 = 7/2
7/2 -= -1/2 = 16/4
16/4 *= -1/2 = -16/8
-16/8 /= -1/2 = -32/-8
-1/2 += 5/1 = 9/2
9/2 -= 5/1 = -1/2
-1/2 *= 5/1 = -5/2
-5/2 /= 5/1 = -5/10

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 8/3
8/3 -= 3 = -1/3
-1/3 *= 3 = -3/3
-3/3 /= 3 = -3/9

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 5/3
Now g = 5/3
g-- = 5/3
Now g = 2/3
--g = -1/3
Now g = -1/3
Press any key to continue . . .*/