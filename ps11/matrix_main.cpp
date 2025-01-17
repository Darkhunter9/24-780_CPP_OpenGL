/*
Carnegie Mellon University
24-780-B Engineering Computation
PS 11: Matrix Manipulation
Due: Tues, Nov. 13, 2018, 11:59pm

*/

#include <stdio.h>
#include <iostream>
#include "matrix_zihaod.h"

int main()
{
	using namespace std;

	Matrix4x4 mat;
	const double v[] = {
		6.0,1.0,4.0,9.0,
		9.0,8.0,6.0,1.0,
		7.0,2.0,9.0,4.0,
		1.0,7.0,5.0,9.0
	};
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			mat.set(i, j, v[(i - 1) * 4 + j - 1]);

	mat.print();

	Matrix4x4 mat2 = mat;  // works because shallow copy is sufficient
	mat2.transpose();
	cout << endl;
	mat.print();
	cout << endl;
	mat2.print();

	// If you go for extra credit, uncomment the following lines.
	//mat.invert();
	//cout << endl;
	//mat.print();
	//mat.invert();
	//cout << endl;
	//mat.print();  // should be the original matrix

	return 0;
}
