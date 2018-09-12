
#include <iostream>
#include <stdio.h>
#include "ballShuffle.h"

using namespace std;

int main() {

	int i;
	int numberOfBalls = 1;
	char currBox[101];
	i = 0;
	while (numberOfBalls > 0)
	{
		cout << "Enter number of balls (even number, 100max, 0 to quit) > ";
		cin >> numberOfBalls;
		if (numberOfBalls <= 0)
			break;             // possible exit from while
		else if (initializeBox(currBox, numberOfBalls)) {  // can create box
			i++;
			printf("Test Case %d (%d balls):\n", i, numberOfBalls);

			printf("          <<   %d moves\n\n",
				shuffle(currBox, numberOfBalls + 1));
			//printf("          <<   %d moves\n\n",
			//	shuffleBlind(currBox, numberOfBalls + 1));
			//printf("          <<   %d moves\n\n",
			//	shuffleRecursive(currBox, numberOfBalls + 1));
		}
		else {
			cout << "Invalid number of balls. Please reenter." << endl;
		}
	}
}