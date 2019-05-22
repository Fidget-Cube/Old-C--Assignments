//***********************************************************//
// Max vonBlankenburg, CS 11, 3/15/18, Dave Harden, a8_1.cpp //
//***********************************************************//
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int SIZE = 24;

struct highscore {
	int score;
	char name[SIZE];
};

void getArraySize(int& size);
void initializeArrays(vector<highscore>& scores);
void sortData(vector<highscore>& scores);
vector<highscore>::iterator indexOfLargest(const vector<highscore>& scores, vector<highscore>::iterator startingIndex);
void displayData(const vector<highscore>& scores);

int main() {
	int arraySize;

	getArraySize(arraySize);
	vector<highscore> scores(arraySize);

	initializeArrays(scores);
	sortData(scores);
	displayData(scores);

	system("PAUSE");
	return 0;
}





void getArraySize(int& size) {
	cout << "How many scores will you enter?: ";
	cin >> size;
	cin.ignore();
}





void initializeArrays(vector<highscore>& scores) {
	for (vector<highscore>::iterator it = scores.begin(); it != scores.end(); it++) {
		cout << "Enter the name for score #" << it - scores.begin() + 1 << ": ";
		cin.getline(it -> name, SIZE, '\n');
		cout << "Enter the score for score #" << it - scores.begin() + 1 << ": ";
		cin >> it -> score;
		cin.ignore();
	}
	cout << endl;
}





void sortData(vector<highscore>& scores) {
	vector<highscore>::iterator largestIndex;

	for (vector<highscore>::iterator it = scores.begin(); it != scores.end() - 1; it++) {
		largestIndex = indexOfLargest(scores, it);
		swap(it->score, largestIndex->score);
		swap(it->name, largestIndex->name);
	}
}





vector<highscore>::iterator indexOfLargest(const vector<highscore>& scores, vector<highscore>::iterator startingIndex) {
	vector<highscore>::iterator targetIndex = startingIndex;
	for (vector<highscore>::iterator it = startingIndex + 1; it != scores.end(); it++) {
		if (it -> score > targetIndex -> score) {
			targetIndex = it;
		}
	}
	return targetIndex;
}





void displayData(const vector<highscore>& scores) {
	cout << "Top Scorers:" << endl;
	for (vector<highscore>::const_iterator it = scores.begin(); it != scores.end(); it++) {
		cout << it -> name << ": " << it -> score << endl;
	}
}

/*
How many scores will you enter?: 5
Enter the name for score #1: Fjonir
Enter the score for score #1: 42
Enter the name for score #2: Griffith
Enter the score for score #2: 47
Enter the name for score #3: Larrus
Enter the score for score #3: 66
Enter the name for score #4: Rylarth
Enter the score for score #4: 12
Enter the name for score #5: Shyla
Enter the score for score #5: 25

Top Scorers:
Larrus: 66
Griffith: 47
Fjonir: 42
Shyla: 25
Rylarth: 12
Press any key to continue . . .*/