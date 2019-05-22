//=======================================================================//
// Max vonBlankenburg, CS 11, Harden, 2/13/18, Fraction.h & Fraction.cpp //
//                                                                       //
// This class is used to create "Fraction" objects that hold two values: //
// "numerator" and "denominator". Fractions can be initialized using two,//
// one, or no arguments, and many operators are overloaded by friend and //
// member functions to be able to be used on fractions. These operators  //
// include the insertion and extraction operators, relational operators, //
// basic arithmetic operators, shorthand assignment operators, and       //
// incrememnt and decrement operators (pre and post).                    //
//                                                                       //
// Fraction(int inNumerator, int inDenominator);                         //
// pre: inNumerator is a fraction numerator, inDenominator is a          //
//      non-negative nonzero fraction denominator.                       //
// post: a fraction object is created with inNumerator as its numerator  //
//       and inDenominator as its denominator.                           //
//                                                                       //
// friend ostream &operator << (ostream &out, const Fraction &fraction); //
// pre: out is an ostream variable, fraction is a mathematical fraction. //
// post: the fraction is printed on the screen in either fraction,       //
//       mixed number, or whole number format depending on the values    //
//       of the fraction numerator and denominator.                      //
//                                                                       //
// friend istream &operator >> (istream &in, Fraction &fraction);        //
// pre: in is an istream variable, fraction is a mathematical fraction.  //
// post: a fraction is read from an input stream in either fraction,     //
//       mixed number, or whole number format and stored in fraction     //
//       as a fraction.                                                  //
//                                                                       //
// friend bool operator < (const Fraction &left, const Fraction &right); //
// pre: left and right are fractions to be compared.                     //
// post: returns true if left is less than right, false otherwise.       //
//                                                                       //
// friend bool operator <= (const Fraction &left, const Fraction &right);//
// pre: left and right are fractions to be compared.                     //
// post: returns true if left is less than or equal to right,            //
//       false otherwise.                                                //
//                                                                       //
// friend bool operator > (const Fraction &left, const Fraction &right); //
// pre: left and right are fractions to be compared.                     //
// post: returns true if left is greater than right, false otherwise.    //
//                                                                       //
// friend bool operator >= (const Fraction &left, const Fraction &right);//
// pre: left and right are fractions to be compared.                     //
// post: returns true if left is greater than or equal to right,         //
//       false otherwise.                                                //
//                                                                       //
// friend bool operator == (const Fraction &left, const Fraction &right);//
// pre: left and right are fractions to be compared.                     //
// post: returns true if left is equal to right, false otherwise.        //
//                                                                       //
// friend bool operator != (const Fraction &left, const Fraction &right);//
// pre: left and right are fractions to be compared.                     //
// post: returns true is left is not equal to right, false otherwise.    //
//                                                                       //
// friend Fraction operator + (Fraction left, const Fraction &right);    //
// pre: left and right are fractions to be added together.               //
// post: returns the sum of both fractions, simplified to lowest terms.  //
//                                                                       //
// friend Fraction operator - (Fraction left, const Fraction &right);    //
// pre: right is a fraction to be subtracted from left, which is also    //
//      a fraction.                                                      //
// post: returns the difference between both fractions, simplified to    //
//       lowest terms.                                                   //
//                                                                       //
// friend Fraction operator * (Fraction left, const Fraction &right);    //
// pre: left and right are fractions to be multiplied together.          //
// post: returns the product of both fractions, simplified to            //
//       lowest terms.                                                   //
//                                                                       //
// friend Fraction operator / (Fraction left, const Fraction &right);    //
// pre: left is a fraction to be divided by right, which is also         //
//      a fraction.                                                      //
// post: returns the quotient of both fractions, simplified to           //
//       lowest terms.                                                   //
//                                                                       //
// Fraction operator += (const Fraction &right);                         //
// pre: right is a fraction to be added on to the calling fraction.      //
// post: the calling fraction is now equal to the calling fraction       //
//       plus right, and the function returns the calling fraction.      //
//                                                                       //
// Fraction operator -= (const Fraction &right);                         //
// pre: right is a fraction to be subtracted from the calling fraction.  //
// post: the calling fraction is now equal to the calling fraction       //
//       minus right, and the function returns the calling fraction.     //
//                                                                       //
// Fraction operator *= (const Fraction &right);                         //
// pre: right is a fraction to be multiplied by the calling fraction.    //
// post: the calling fraction is now equal to the calling fraction       //
//       times right, and the function returns the calling fraction.     //
//                                                                       //
// Fraction operator /= (const Fraction &right);                         //
// pre: right is a fraction to be divided by the calling fraction.       //
// post: the calling fraction is now equal to the calling fraction       //
//       divided by right, and the function returns the calling fraction.//
//                                                                       //
// Fraction operator ++ ();                                              //
// pre: a fraction is called to be incremented.                          //
// post: the calling fraction is now equal to the calling fraction       //
//       plus 1, and the function returns the calling fraction's         //
//       current value.                                                  //
//                                                                       //
// Fraction operator ++ (int);                                           //
// pre: a fraction is called to be incremented.                          //
// post: the calling fraction is now equal to the calling fraction       //
//       plus 1, and the function returns the calling fraction's         //
//       value before it was incremented.                                //
//                                                                       //
// Fraction operator -- ();                                              //
// pre: a fraction is called to be decremented.                          //
// post: the calling fraction is now equal to the calling fraction       //
//       minus 1, and the function returns the calling fraction's        //
//       current value.                                                  //
//                                                                       //
// Fraction operator -- (int);                                           //
// pre: a fraction is called to be decremented.                          //
// post: the calling fraction is now equal to the calling fraction       //
//       minus 1, and the function returns the calling fraction's        //
//       value before it was decremented.                                //
//=======================================================================//
#include <iostream>

namespace cs_Fraction {
	class Fraction {
	private:
		int numerator;
		int denominator;
		void simplify();
	public:
		Fraction(int = 0, int = 1);
		friend std::ostream &operator << (std::ostream &, const Fraction &);
		friend std::istream &operator >> (std::istream &, Fraction &);
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
}