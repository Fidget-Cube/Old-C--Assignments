/*
The "numerator" data member holds a value to signify the numerator of a fraction.
The "denominator" data memeber holds a value to signify the denominator of a fraction.
The denominator of a fraction will never equal 0.
Fractions will always be stored in lowest terms.
Improper fractions will always be printed in mixed number format.
Whole number fractions will always be printed as whole numbers.*/
#include <iostream>
#include "Fraction.h"
#include <cassert>
#include <cmath>
using namespace std;

namespace cs_Fraction {

	// pre: called fraction object is a fraction that may or may not be simplified.
	// post: fraction object does not have a denominator equal to or less than 0, and is simplified to lowest terms.
	void Fraction::simplify() {
		bool isPrime;
		if (denominator == 0 || numerator == 0)
			denominator = 1;
		else if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
		for (int x = denominator; x > 1; x--) {
			isPrime = true;
			for (int y = 2; y < x; y++) {
				if (x % y == 0)
					isPrime = false;
			}
			while (isPrime && numerator % x == 0 && denominator % x == 0) {
				numerator /= x;
				denominator /= x;
			}
		}
	}





	Fraction::Fraction(int inNumerator, int inDenominator) {
		assert(inDenominator != 0);
		numerator = inNumerator;
		denominator = inDenominator;
		simplify();
	}





	ostream &operator << (ostream &out, const Fraction &fraction) {
		if (abs(fraction.numerator) % fraction.denominator == 0)
			return out << fraction.numerator / fraction.denominator;
		else if (abs(fraction.numerator) < fraction.denominator)
			return out << fraction.numerator << '/' << fraction.denominator;
		else
			return out << fraction.numerator / fraction.denominator << '+' << abs(fraction.numerator) % fraction.denominator << '/' << fraction.denominator;
	}





	istream &operator >> (istream &in, Fraction &fraction) {
		int leadNum = 0;
		bool breaker = false;

		while (!breaker) {
			in >> fraction.numerator;
			if (in.peek() == '+') {
				leadNum = fraction.numerator;
				in.ignore();
			}
			else if (in.peek() == '/') {
				in.ignore();
				in >> fraction.denominator;
				breaker = true;
			}
			else
				breaker = true;
		}
		if (leadNum) {
			fraction.numerator += abs(leadNum) * fraction.denominator;
			if (leadNum < 0)
				fraction.numerator *= -1;
		}
		fraction.simplify();
		return in;
	}





	bool operator < (const Fraction &left, const Fraction &right) {
		return (left.numerator * right.denominator) < (right.numerator * left.denominator);
	}





	bool operator <= (const Fraction &left, const Fraction &right) {
		return (left.numerator * right.denominator) <= (right.numerator * left.denominator);
	}





	bool operator > (const Fraction &left, const Fraction &right) {
		return (left.numerator * right.denominator) > (right.numerator * left.denominator);
	}





	bool operator >= (const Fraction &left, const Fraction &right) {
		return (left.numerator * right.denominator) >= (right.numerator * left.denominator);
	}





	bool operator == (const Fraction &left, const Fraction &right) {
		return (left.numerator * right.denominator) == (right.numerator * left.denominator);
	}





	bool operator != (const Fraction &left, const Fraction &right) {
		return (left.numerator * right.denominator) != (right.numerator * left.denominator);
	}





	Fraction operator + (Fraction left, const Fraction &right) {
		left.numerator = (left.numerator * right.denominator) + (right.numerator * left.denominator);
		left.denominator *= right.denominator;
		left.simplify();
		return left;
	}





	Fraction operator - (Fraction left, const Fraction &right) {
		left.numerator = (left.numerator * right.denominator) - (right.numerator * left.denominator);
		left.denominator *= right.denominator;
		left.simplify();
		return left;
	}





	Fraction operator * (Fraction left, const Fraction &right) {
		left.numerator *= right.numerator;
		left.denominator *= right.denominator;
		left.simplify();
		return left;
	}





	Fraction operator / (Fraction left, const Fraction &right) {
		left.numerator *= right.denominator;
		left.denominator *= right.numerator;
		left.simplify();
		return left;
	}





	Fraction Fraction::operator += (const Fraction &right) {
		*this = *this + right;
		return *this;
	}





	Fraction Fraction::operator -= (const Fraction &right) {
		*this = *this - right;
		return *this;
	}





	Fraction Fraction::operator *= (const Fraction &right) {
		*this = *this * right;
		return *this;
	}





	Fraction Fraction::operator /= (const Fraction &right) {
		*this = *this / right;
		return *this;
	}





	Fraction Fraction::operator ++ () {
		*this = *this + 1;
		return *this;
	}





	Fraction Fraction::operator ++ (int) {
		Fraction temp(*this);
		*this = *this + 1;
		return temp;
	}





	Fraction Fraction::operator -- () {
		*this = *this - 1;
		return *this;
	}





	Fraction Fraction::operator -- (int) {
		Fraction temp(*this);
		*this = *this - 1;
		return temp;
	}
}


/*

----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to 1/2
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false
Comparing 1/2 to -1/2
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing -1/2 to 1/10
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing 1/10 to 0
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing 0 to 0
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
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
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
Press any key to continue . . .*/