/*
   _____                _____   Zihao Ding
  |     | _____        |     |  Carnegie Mellon University
  |  3  ||     | _____ |  2  |  Engineering Computation, 24-780-B
  |  x  ||  5  ||     ||  x  |  Prob Set 6-1. 10/07/2018
  |  7  ||  x  ||  4  ||  6  |  
  |_____||  2  ||  x  ||_____|  Digital (text-only) version of 
		 |_____||  9  |         multiplication flash cards. Program
				|_____|         assures non-repeating questions while
							    keeping track of time and score.

								Using class FlashCard
*/

#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "FlashCard_zihaod.h"

using namespace std;

void printArray(FlashCard theArray[], int size)
{
	for (int i = 0; i < size; i++) {
		theArray[i].present();
		cout << endl;
	}
	cout << endl;
}

void swapArray(FlashCard theArray[], int left, int right)
{
	FlashCard temp = theArray[left];
	theArray[left] = theArray[right];
	theArray[right] = temp;
}

void shuffleArray(FlashCard theArray[], int size)
{
	int randLoc;
	srand((int)time(NULL));
	for (int i = 0; i < size; i++) {
		randLoc = rand() % size;
		swapArray(theArray, i, randLoc);
	}
}

int main()
{
	bool badCardCountEntry;
	time_t startTime;
	char userInputChar;
	int numbOfCards, userAnswer, correctCounter;
	int arraySize, maxMulti;
	FlashCard flashCardArray[144];

	// title and setup
	cout << "____________Multiplication Flash Cards___________" << endl;
	cout << endl;
	cout << "Would you like to include products of 11 and 12? [y/n] > ";
	cin >> userInputChar;

	if (userInputChar == 'Y' || userInputChar == 'y')
		arraySize = 144;
	else
		arraySize = 100;
	maxMulti = (int)sqrt(arraySize);
	//printArray(flashCardArray, arraySize);

	badCardCountEntry = true;
	while (badCardCountEntry){
		cout << "How many questions would you like in this session? > ";
		cin >> numbOfCards;
		badCardCountEntry = (numbOfCards < 1 || numbOfCards > arraySize);
		if (badCardCountEntry) 
			cout << "ERROR: Please enter a size between 1 and "  
				<< arraySize << "." <<endl;
	} 

	// generate array and shuffle
	for (int i = 0; i < arraySize; i++) {
		flashCardArray[i] = FlashCard(i / maxMulti + 1, i % maxMulti + 1);
	}
	//printArray(flashCardArray, arraySize);
	shuffleArray(flashCardArray, arraySize);
	//printArray(flashCardArray, arraySize);

	// generate questions and check responses
	startTime = time(NULL);
	correctCounter = 0;

	for (int i = 0; i < numbOfCards; i++) {
		flashCardArray[i].present();
		cin >> userAnswer;

		if (userAnswer == flashCardArray[i].solution())
			correctCounter++;
		else
		{
			cout << "Incorrect! ";
			flashCardArray[i].present();
			cout << flashCardArray[i].solution() << endl;
		}
	}

	// provide session summary
	cout << "You answered " << numbOfCards << " problems in "  
		<< time(NULL) - startTime << " seconds." << endl;
	cout.precision(4);
	cout << "You answered " << correctCounter << " problems correctly (" 
		<< (double)correctCounter / numbOfCards * 100. << " % )." << endl;

}

