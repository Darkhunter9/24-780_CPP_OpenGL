/*
24-780-B Engineering Computation Problem Set 6-2 - Animate spring mass
Name: Zihao Ding
Andrew ID: zihaod
Date: 10/07/2018
Description:
The program shows a schematic drawing of a mass-spring system, with animation of bounding/rebounding.
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fssimplewindow.h"
#include "SpringMass_zihaod.h"

using namespace std;

int main(void)
{
	//open window
	FsOpenWindow(16, 16, 800, 600, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//input parameters
	double L, h;
	cout << "24-780 Engineering Computation Problem Set 2-2 - Mass-Spring System\n" << endl;
	cout << "reference value: L 5, h 1" << endl;
	cout << "Enter L and h:";
	cin >> L >> h;

	//realize animation
	bool rebound = false;
	double L2 = L;
	double velocity = 0;
	double acceleration = 0;
	double timestep;
	FsPassedTime();
	while (FSKEY_ESC != FsInkey())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		drawWall();
		drawSpring(L2*50, h*50);
		drawMass(L2*50, h*50);
		glFlush();

		timestep = 0.001*FsPassedTime();
		acceleration = 3 - L2;
		velocity += timestep * acceleration;
		L2 += velocity * timestep;

		FsPollDevice();
		FsSleep(10);

		
	}

	return 0;
}