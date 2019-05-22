//=========================================================================================//
// Max vonBlankenburg, 5/17/18
// Most of the credit for this program goes to some guy in my CS 11 class
//
// Font length and height must be 6 and 7 respectively.
//
//=========================================================================================//
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cctype>
#include <string>
#include <fstream>
using std::cout;

void placeCursor(HANDLE, int, int);

const char PIXEL = 219;

int main()
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	string message;
	int counter = 79,                           // 79 is the width of the console, it counts down from 79 to 0 which gives the effect of scrolling left
		length,
		offset = 0,
		chara;
	bool acrossScreen = false;
	char holding;
	char* characters[7];

	cout << "Enter a message to scroll: ";
	getline(cin, message);

	message += "   ";                           // adds 3 spaces to the end of the message to give a little room inbetween each message
	length = message.length();

	/////
	for (int i = 0; i < 7; i++) {
		characters[i] = new char[length * 6];          // defines array that will hold the pixel font
	}

	ifstream inputFile;                         // This file holds the pixel font
	string fileName = "font.txt",
		pixelFont;
	int messageCounter,
		rowCounter;

	for (int messageCounter = 0; messageCounter < message.length(); messageCounter++) {             // loops for every character there is in the message
		holding = message[messageCounter];
		if (holding != ' ') {                                                                       // if the character is a space it just makes a 6x7 area in the array full of spaces
			inputFile.open(fileName.c_str());
			for (int i = 0; i < toupper(message[messageCounter]) - 64; i++) {                       // Loops for the number of the character in the alphabet (a=1;z=26)
				inputFile >> pixelFont;                                                             // Finds the instructions for the pixel font for that character
			}
			for (int rowCounter = 0; rowCounter < 7; rowCounter++) {                                // Loops 7 times
				for (int i = 0; i < 6; i++) {                                                       // Loops 6 times (the pixel font is 6 spaces wide by 7 spaces tall)
					holding = pixelFont[(rowCounter * 6) + i];
					if (holding == '0') {                                                           // If the instructions give a 0 it means a space and a 1 means a #
						characters[rowCounter][messageCounter * 6 + i] = ' ';
						//characters[messageCounter * 6 + i][rowCounter] = ' ';
					}
					else {
						characters[rowCounter][messageCounter * 6 + i] = PIXEL;
						//characters[messageCounter * 6 + i][rowCounter] = PIXEL;
					}
				}
			}
			inputFile.close();                                                                      // closes input file so it can re-open it on next loop
		}
		else {
			for (int rowCounter = 0; rowCounter < 7; rowCounter++) {
				for (int i = messageCounter * 6; i < messageCounter * 6 + 6; i++) {
					characters[rowCounter][i] = ' ';
				}
			}
		}

	}


	system("CLS");                                                                                  // Clear Screen

	length *= 6;                                                                                    // Multiply length by 6 so it is the length of the array not the message

	while (true) {                                                                                  // Infinite loop
		for (int rowCounter = 0; rowCounter < 7; rowCounter++) {

			placeCursor(screen, counter, 9 + rowCounter);

			for (int i = 0; i < 80 - counter; i++) {
				chara = (i % length) + offset;
				chara %= length;
				cout << characters[rowCounter][chara];
			}
		}



		counter--;

		if (counter < 0) {
			counter = 0;
			acrossScreen = true;
		}

		if (acrossScreen) {
			offset++;

			if (offset >= length) {
				offset = 0;
			}
		}

		Sleep(100);         // 100 millisecond cooldown before continuing the program

	}

	return 0;
}




void placeCursor(HANDLE screen, int col, int row)
{
	COORD position;
	position.X = col;
	position.Y = row;
	SetConsoleCursorPosition(screen, position);
}
