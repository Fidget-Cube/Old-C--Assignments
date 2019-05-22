#include "sequence.h"
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace cs_sequence;

int main() {
	Sequence<int> s;
	Sequence<char> c;

	for (int i = 0; i < 6; i++) {
		s.insert(i);
		c.insert('a' + i);
	}

	for (s.start(); s.is_item(); s.advance()) {
		cout << s.current() << " ";
	}
	cout << endl;
	for (c.start(); c.is_item(); c.advance()) {
		cout << c.current() << " ";
	}
	cout << endl;

	cout << s.size() << ' ' << c.size() << endl;

	system("pause");
}