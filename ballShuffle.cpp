#include <iostream>
#include <stdio.h>
#include "ballShuffle.h"

using namespace std;

bool initializeBox(char aBox[], int numberOfBalls)
{
	if (numberOfBalls % 2 == 1) //  requested number of balls is odd
		return false;
	else
	{
		for (int i = 0; i < numberOfBalls / 2; i++)
		{
			aBox[i] = 'G';
			aBox[numberOfBalls - i] = 'R';
		}
		aBox[numberOfBalls / 2] = ' ';
		aBox[numberOfBalls + 1] = END_OF_BOX;
		return true;
	}
}


int moveAll(char theBox[], int boxSize, int direction)
{
	int moveCount = 0;
	int currIndex;
	int limitIndex;
	char lookForChar;
	bool lastMoveWasShift = false;

	// initialize based on direction of movement
	if (direction == -1)       // move red balls towards left
	{
		limitIndex = 0;        // start processing at left end
		lookForChar = 'R';     // move the red balls
	}
	else                       // move green balls towards right
	{
		limitIndex = boxSize;  // start processing at right end
		lookForChar = 'G';     // move the green balls
	}

	currIndex = limitIndex;    // initialize currIndex

	// step through the box, looking for balls to move
	while (currIndex >= 0 && currIndex <= boxSize)
	{
		if (theBox[currIndex] == lookForChar)  // need to process
		{
			if (currIndex != limitIndex
				&& theBox[currIndex + direction] == ' ')// shift is possible 
			{
				if (lastMoveWasShift)  // never allow two shifts in a row
					break;             // <<<<<<< POSSIBLE EXIT FROM WHILE LOOP

				swapArray(theBox, currIndex, currIndex + direction); // do shift
				lastMoveWasShift = true;						// set flag
				moveCount++;                                    // update count
				printBox(theBox);					// output state

			}
			else if (abs(currIndex - limitIndex) > 0
				&& theBox[currIndex + direction * 2] == ' ')  // try a jump
			{
				swapArray(theBox, currIndex, currIndex + direction * 2); // do jump
				lastMoveWasShift = false;					 	// set flag
				moveCount++;					                // update count
				printBox(theBox);					// output state
			}

		}

		currIndex += -direction; // advance currIndex in opposite direction
	}
	return moveCount;
}

int shuffle(char theBox[], int boxSize)
{
	int numberOfMoves = 0;
	int currMoveCount = 1;
	int direction = -1;

	// print initial state
	printBox(theBox);

	// make all possible moves in one direction, then change directions
	// repeat until there are no more moves
	while (currMoveCount > 0)
	{
		currMoveCount = moveAll(theBox, boxSize, direction);
		direction *= -1;
		numberOfMoves += currMoveCount;
	}

	return numberOfMoves;
}

int shuffleBlind(char theBox[], int boxSize)
{
	int ballsPerSide = (boxSize - 1) / 2;
	int delta = 1;
	int indexOfBlank = ballsPerSide;

	// print initial state
	printBox(theBox);

	for (int i = 1; i <= ballsPerSide; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == i)
				delta = abs(delta) / delta;
			swapArray(theBox, indexOfBlank, indexOfBlank + delta);
			indexOfBlank += delta;
			printBox(theBox);					// output state
		}
		delta = abs(delta) / delta * -2;
	}

	for (int i = 1; i <= ballsPerSide; i++)
	{
		swapArray(theBox, indexOfBlank, indexOfBlank + delta);
		indexOfBlank += delta;
		printBox(theBox);					// output state
	}
	delta = abs(delta) / delta * -2;

	for (int i = ballsPerSide; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
				delta = abs(delta) / delta;
			swapArray(theBox, indexOfBlank, indexOfBlank + delta);
			indexOfBlank += delta;
			printBox(theBox);					// output state
			delta = abs(delta) / delta * 2;
		}
		delta = abs(delta) / delta * -2;
	}
	return ballsPerSide * (ballsPerSide + 2);
}


void swapArray(char theBox[], int indexA, int indexB)
{
	char temp = theBox[indexA];
	theBox[indexA] = theBox[indexB];
	theBox[indexB] = temp;
}


void printBox(char theBox[]) {
	int i = 0;
	while (theBox[i] != END_OF_BOX)
	{
		printf("%c", theBox[i]);
		i++;
	}

	printf("\n");
}
