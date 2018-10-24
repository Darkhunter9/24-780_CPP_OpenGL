#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

int main(void)
{
	double myArray[10][3] = {};
	myArray[2][1] = 999;
	double *middle = &myArray[2][1];
	middle[10] = 12.345;
	cout << myArray[4][2];
	cout << middle[10];

	system("pause");
	return 0;
}