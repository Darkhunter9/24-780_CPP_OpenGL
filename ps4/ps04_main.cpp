#include <stdio.h>
#include <iostream>
#include "fssimplewindow.h"
#include "ps04_zihaod.h"

int main(void)
{
	int arrayToSort[20];

	FsOpenWindow(16, 16, 400, 400, 1);

	fillAndRandomizeArray(arrayToSort, 20);

	bubbleSort(arrayToSort, 20);

	while (FSKEY_ESC != FsInkey())
	{
		FsPollDevice();
		FsSleep(10);
	}

	fillAndRandomizeArray(arrayToSort, 20);

	quickSort(arrayToSort, 0, 20 - 1, 20);

	while (FSKEY_ESC != FsInkey())
	{
		FsPollDevice();
		FsSleep(10);
	}

	return 0;
}
