#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LL.h"
#include "binarytree.h"
using std::cout;
using std::cin;

int main() {
	binarytree list;
	int num;
	bool found;
	srand((time(0)));

	/*cout << "enter number to insert (negative to quit): ";
	cin >> num;
	while (num >= 0) {
		list.insert(num);
		cout << "enter number to insert (negative to quit): ";
		cin >> num;
	}*/
	
	for (int i = 0; i < 10; i++) {
		list.insert(1 + rand() % 20);
	}

	list.print();
	cout << endl;

	binarytree::size_type numItems;
	numItems = list.size();
	cout << "There are " << numItems << " items." << endl;



	cout << "enter a number to find (negative to quit): ";
	cin >> num;
	while (num >= 0) {
		int result = list.find(num, found);
		if (!found) {
			cout << "not found" << endl;
		}
		else {
			cout << "found.  The data is " << result << endl;
		}
		cout << "enter a number to find (negative to quit): ";
		cin >> num;
	}


	cout << "enter a number to delete (negative to quit): ";
	cin >> num;
	while (num >= 0) {
		list.del(num, found);
		if (found) {
			cout << "the list is now ";
			list.print();
			cout << endl;
		}
		else {
			cout << num << " is not in the list." << endl;
		}
		cout << "enter a number to delete (negative to quit): ";
		cin >> num;
	}


	int primes = list.numPrimes();
	cout << "There are " << primes << " prime numbers in the list." << endl;

	LL<int> l;
	l = list.toLL();

	cout << "The linked list: ";

	for (LL<int>::iterator i = l.begin(); i != l.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	cout << "The original binary tree still intact: ";
	list.print();
	cout << endl;

	
	binarytree list2(list);

	cout << "Now list 2 should be a copy of list.  Here it is: ";
	list2.print();
	cout << endl;


	list2.del(3, found);


	cout << "After deleting a 3 from list2, list2 is now: ";
	list2.print();
	cout << endl << "list should be unchanged.  Here it is: ";
	list.print();
	cout << endl;

	list = list2;

	cout << "Now list has been assigned list2 so it should match list2.  Here it is: ";
	list.print();
	cout << endl;

	list.del(4, found);

	cout << "After deleting a 4 from list, list is now: ";
	list.print();
	cout << endl << "list2 should be unchanged.  Here it is: ";
	list2.print();
	cout << endl;
	

	system("pause");
}