/*
24-780-B Engineering Computation Problem Set 3 - Spring-mass system drawing
Name: Zihao Ding
Andrew ID: zihaod
Date: 09/16/2018
Description:
The program shows a schematic drawing of a mass-spring system, with animation of bounding/rebounding.
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fssimplewindow.h"
#include "springMass_zihaod.h"

using namespace std;

int main(void)
{
	//open window
	FsOpenWindow(16, 16, 800, 600, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//input parameters
	double L, h;
	cout << "24-780 Engineering Computation Problem Set 2-2 - Mass-Spring System\n" << "Enter L and h:";
	cin >> L >> h;

	//realize animation
	bool rebound = false;
	double L2 = L;
	while (FSKEY_ESC != FsInkey())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		drawWall();
		drawSpring(L2, h);
		drawMass(L2, h);
		glFlush();
		if (! rebound)
		{
			L2 -= pow((L2/L), 2)*L/100;
			if (L2 < L/3)
			{
				rebound = true;
			}
		}
		else
		{
			L2 += pow((L2/L), 2)*L/100;
			if (L2 >= L)
			{
				rebound = false;
			}
		}

		FsPollDevice();
		FsSleep(10);
	}

	return 0;
}