//=======================================================================//
// Max vonBlankenburg, CS 11, Harden, 2/22/18, mystring.h & mystring.cpp //
// This "MyString" class includes one data member, a character string,   //
// and several member and friend functions to work with this character   //
// string. These include the "big 3" constructors and a destructor, a    //
// function that returns the length of the string, insertion and         //
// extraction operator overloads, a "read" function that acts like a     //
// cin.getline function for c-strings, and overloads for the square      //
// brackets [], concatenation +, concatenation & assignment +=, and      //
// all relational operators.                                             //
//-----------------------------------------------------------------------//
// MyString();
// 
// pre: A MyString object has been created with no parameters.
// post: The object's "stringData" member variable is initialized to "".
//
// MyString(const char[]);
// 
// pre: A MyString object has been created with character array "stringy"
//      as its parameter.
// post: The object's "stringData" member variable is initialized to stringy.
//
// MyString operator=(const MyString&);
// 
// pre: A MyString object or character array "stringy" is called by the
//      assignment operator.
// post: The calling object's "stringData" variable is assigned to the
//       value of stringy.
//
// MyString(const MyString&);
//
// pre: A MyString object has been created with MyString object "stringy"
//      as its parameter.
// post: The object's "stringData" variable is initialized to match stringy's
//       "stringData" variable.
//
// ~MyString();
//
// pre: A MyString object is being destroyed.
// post: The data referenced by the object's "stringData" variable is
//       deallocated.
//
// int length() const;
//
// pre: A MyString object calls a parameter-less function.
// post: The function returns the length of the object's "stringData"
//       c-string variable.
//
// friend std::ostream &operator << (std::ostream&, const MyString&);
//
// pre: The insertion operator calls ostream variable "out" and MyString
//      object "stringy" as parameters.
// post: The function sends stringy's "stringData" variable to the output 
//       stream, then returns out.
//
// friend std::istream &operator >> (std::istream&, MyString&);
//
// pre: The extraction operator calls istream variable "in" and MyString
//      object "stringy" as parameters.
// post: Input is obtained from the user and stored in stringy's "stringData" 
//       variable, then the function returns in.
//
// void read(std::istream&, char);
//
// pre: This function calls istream variable "in" and char "delimiter" as
//      parameters.
// post: A line of input is obtained from the user and stored in the
//       calling object's "stringData" variable.
//
// char operator[](int) const;
//
// pre: The square brackets operator calls int variable "index" as a parameter.
// post: If "index" is between 0 and the length of the calling object's "stringData"
//       variable, the function returns the character in stringData at the
//       array index "index".
//
// char& operator[](int);
//
// pre: The square brackets operator calls int variable "index" as a parameter.
// post: If "index" is between 0 and the length of the calling object's "stringData"
//       variable, the function returns a reference to the character in stringData 
//       at the array index "index".
//
// friend MyString operator+(const MyString&, const MyString&);
//
// pre: The + operator calls two MyString objects "left" and "right" as parameters.
// post: The function returns a character array holding the value of left appended
//       to the value of right.
//
// MyString operator+=(const MyString&);
//
// pre: The += operator calls MyString object "stringy" as a parameter.
// post: The function appends stringy's "stringData" variable the calling
//       object's stringData variable, then returns the result.
//
// friend bool operator<(const MyString&, const MyString&);
//
// pre: The < operator calls two MyString objects "left" and "right" as parameters.
// post: The function returns true if the ascii value of left is less than right,
//       false otherwise.
//
// friend bool operator<=(const MyString&, const MyString&);
//
// pre: The <= operator calls two MyString objects "left" and "right" as parameters.
// post: The function returns true if the ascii value of left is less than or equal
//       to right, false otherwise.
//
// friend bool operator>(const MyString&, const MyString&);
//
// pre: The > operator calls two MyString objects "left" and "right" as parameters.
// post: The function returns true if the ascii value of left is greater than right,
//       false otherwise.
//
// friend bool operator>=(const MyString&, const MyString&);
//
// pre: The >= operator calls two MyString objects "left" and "right" as parameters.
// post: The function returns true if the ascii value of left is greater than or equal
//       to right, false otherwise.
//
// friend bool operator==(const MyString&, const MyString&);
//
// pre: The == operator calls two MyString objects "left" and "right" as parameters.
// post: The function returns true if the ascii value of left is equal to right, 
//       false otherwise.
//
// friend bool operator!=(const MyString&, const MyString&);
//
// pre: The != operator calls two MyString objects "left" and "right" as parameters.
// post: The function returns true if the ascii value of left is not equal to right, 
//       false otherwise.
//
//====================================================================================//
#include <iostream>

namespace cs_mystring {
	class MyString {
	private:
		char *stringData;
	public:
		MyString();
		MyString(const char[]);
		MyString operator=(const MyString&);
		MyString(const MyString&);
		~MyString();
		int length() const;
		friend std::ostream &operator << (std::ostream&, const MyString&);
		friend std::istream &operator >> (std::istream&, MyString&);
		void read(std::istream&, char);
		char operator[](int) const;
		char& operator[](int);
		friend MyString operator+(const MyString&, const MyString&);
		MyString operator+=(const MyString&);
		friend bool operator<(const MyString&, const MyString&);
		friend bool operator<=(const MyString&, const MyString&);
		friend bool operator>(const MyString&, const MyString&);
		friend bool operator>=(const MyString&, const MyString&);
		friend bool operator==(const MyString&, const MyString&);
		friend bool operator!=(const MyString&, const MyString&);
	};
}