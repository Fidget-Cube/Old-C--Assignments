//***********************************************************//
// Max vonBlankenburg, CS 11, 1/23/18, Dave Harden, a1_2.cpp //
// This program accepts scores from a user for a fictitious  //
// game, sorts them, and displays them in descending order.  //
// It starts by asking the user for the amount of scores     //
// wanted, then uses that value to allocate two dynamic      //
// arrays of that size. It then runs three functions that    //
// obtain from the user each name and corresponding score,   //
// sort the scores along with their names in descending      //
// order, and display them in that order.                    //
//***********************************************************//
#include <iostream>
#include <string>
#include <cstdlib>

void initializeArrays(std::string[], int[], int);
void sortData(std::string[], int[], int);
void displayData(const std::string[], const int[], int);

//The main function creates two dynamic arrays sized based on user input,
//then runs three functions to initialize them, sort them, and display them.
int main() {
    int arraySize;

    std::cout << "How many scores will you enter?: ";
    std::cin >> arraySize;
    std::string* names = new std::string[arraySize];
    int* scores = new int[arraySize];

    initializeArrays(names, scores, arraySize);
    sortData(names, scores, arraySize);
    displayData(names, scores, arraySize);

    system("PAUSE");
    return 0;
}

//This function asks the user for a score and a name associated with it for
//each element of the arrays, then stores those values in their respective arrays.
void initializeArrays(std::string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the name for score #" << i + 1 << ": ";
        std::cin >> names[i];
        std::cout << "Enter the score for score #" << i + 1 << ": ";
        std::cin >> scores[i];
    }
}

//This function does a selection sort on the values in the "scores" array.
//For each element of the array besides the first, it compares said element
//to the one before it, and switches the values in each if said element is larger.
//The function continues with a while loop until no more switches are performed.
void sortData(std::string names[], int scores[], int size) {
    int switches = 0;

    do {
    switches = 0;
    std::string tempName;
    int tempScore;

        for (int i = 1; i < size; i++) {
            if (scores[i] > scores[i-1]) {
                tempName = names[i]; names[i] = names[i-1]; names[i-1] = tempName;
                tempScore = scores[i]; scores[i] = scores[i-1]; scores[i-1] = tempScore;
                switches++;
            }
        }
    } while (switches > 0);
}

//This function displays the name and respective score of each array element in descending order.
void displayData(const std::string names[], const int scores[], int size) {
    std::cout << "\nTop Scorers:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << names[i] << ": " << scores[i] << std::endl;
    }
}

/*
How many scores will you enter?: 4
Enter the name for score #1: Suzy
Enter the score for score #1: 600
Enter the name for score #2: Kim
Enter the score for score #2: 9900
Enter the name for score #3: Armando
Enter the score for score #3: 8000
Enter the name for score #4: Tim
Enter the score for score #4: 514

Top Scorers:
Kim: 9900
Armando: 8000
Suzy: 600
Tim: 514
Press any key to continue . . .*/
