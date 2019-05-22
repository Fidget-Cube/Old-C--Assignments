//=======================================================================//
// Max vonBlankenburg, CS 11, Harden, 2/22/18, mystring.h & mystring.cpp //
//=======================================================================//
#include <iostream>
using namespace std;

namespace cs_mystring {
	class MyString {
	private:
		char *stringData;
	public:
		MyString();
		MyString(const char[]);
		void operator=(const MyString&);
		MyString(const MyString&);
		~MyString();
		int length() const;
		friend ostream &operator << (ostream&, const MyString&);
		char operator[](int) const;
		char& operator[](int);
		friend bool operator<(const MyString&, const MyString&);
		friend bool operator<=(const MyString&, const MyString&);
		friend bool operator>(const MyString&, const MyString&);
		friend bool operator>=(const MyString&, const MyString&);
		friend bool operator==(const MyString&, const MyString&);
		friend bool operator!=(const MyString&, const MyString&);
	};
}