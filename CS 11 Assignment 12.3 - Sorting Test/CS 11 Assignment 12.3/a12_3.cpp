//===================================================//
// Max vonBlankenburg, 4/17/18, CS 11, Harden, a12_3 //
//===================================================//
// This program generates a random array of ints and //
// sorts it using a recursive function implementing  //
// a selection sort.                                 //
//===================================================//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10;

void selectionSort(int array[], int size);
void rangeSort(int array[], int start, int end);
int indexOfSmallest(int array[], int start, int end);

int main() {
	int array[SIZE];
	srand((time(0)));

	cout << "Unsorted Array: ";
	for (int i = 0; i < SIZE; i++) {
		array[i] = (1 + rand() % 100);
		cout << array[i] << ' ';
	}
	cout << endl;

	selectionSort(array, SIZE);

	cout << "Sorted Array: ";
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;

	system("pause");
}





// This function calls rangeSort with a start variable of 0
// and an end variable of one less than size.
void selectionSort(int array[], int size) {
	rangeSort(array, 0, size - 1);
}





// This recursive function sorts array using a selection sort.
// It first determines if end is larger than start, then calls 
// indexOfSmallest to find the index of the smallest number in 
// array, then swaps that number with the number at start, and finally
// calls selectionSort with a start value of one greater.
void rangeSort(int array[], int start, int end) {
	if (start < end) {
		int smallest = indexOfSmallest(array, start, end);
		int temp = array[start];
		array[start] = array[smallest];
		array[smallest] = temp;
		rangeSort(array, start + 1, end);
	}
}





// This recursive function finds the index of the smallest number
// in array from start to end. If start is less than end, it simply
// returns start; otherwise, it calls indexOfSmallest with a start
// variable one larger, compares the element at the result index to 
// the element at start, and returns the smaller of the two.
int indexOfSmallest(int array[], int start, int end) {
	if (start < end) {
		int smallest = indexOfSmallest(array, start + 1, end);
		if (array[start] <= array[smallest]) {
			return start;
		}
		return smallest;
	}
	return start;
}





/*
Unsorted Array: 81 82 67 56 24 4 66 43 35 26
Sorted Array: 4 24 26 35 43 56 66 67 81 82
Press any key to continue . . .*/