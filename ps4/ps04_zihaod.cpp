#include "fssimplewindow.h"
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void visualizeArrayContents(int input[], int size)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < size; i++)
	{	
		glBegin(GL_QUADS);
		glVertex2i(0, 20*i);
		glVertex2i(20*input[i], 20*i);
		glVertex2i(20*input[i], 20*(i+1));
		glVertex2i(0, 20*(i+1));
		glEnd();
	}
	FsSwapBuffers();
	glFlush();
}

void swapInt(int &left, int &right)
{
	int temp = left;
	left = right;
	right = temp;
}

void shuffleArray(int theArray[], int size)  // from PS02
{
	int randLoc;
	srand((int)time(NULL));
	for (int i = 0; i < size; i++) {
		randLoc = rand() % size;
		swapInt(theArray[i], theArray[randLoc]);
	}
}

void fillAndRandomizeArray(int arrayToInit[], int size)
{
	for (int i = 0; i < size; i++)
		arrayToInit[i] = i + 1;

	shuffleArray(arrayToInit, size);
}

void visualizeAndPause(int input[], int size)
{
	visualizeArrayContents(input, size);
	FsPollDevice();
	while (FSKEY_SPACE != FsInkey())
	{
		FsPollDevice();
		FsSleep(10);
	}
}

void bubbleSort(int input[], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		// process right part of array
		for (j = i + 1; j < size; j++) 
			if (input[i] > input[j])
				swapInt(input[i], input[j]);
		
		// visualize and pause at every step
		visualizeAndPause(input, size);
	}
}

void quickSort(int input[], int lowerBound, int upperBound, int size)
{ // size is only needed for visualization

	if (lowerBound < upperBound) {


		// select the left most value as the pivot value
		int pivotIndex = lowerBound;

		// move all values less than value at pivotIndex to left of pivot value
		for (int i = lowerBound + 1; i <= upperBound; i++)
			if (input[i] <= input[pivotIndex]) {
				swapInt(input[pivotIndex], input[i]);
				swapInt(input[i], input[pivotIndex + 1]);
				pivotIndex++;
			}

		// visualize and pause at every step
		visualizeAndPause(input, size);

		// call for sort of left and right sides of pivot
		quickSort(input, lowerBound, pivotIndex - 1, size);
		quickSort(input, pivotIndex + 1, upperBound, size);
	}
}