// Drawing lines 9/12/18

#include <stdio.h>
#include "fssimplewindow.h"
#include <math.h>
#define PI 3.14159

int main(void)
{
	const int WINSIZE = 600;
	FsOpenWindow(16, 16, 800, 600, 0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0, 10.0, 1.0);
	glBegin(GL_LINES);
	for (int i = 0; i <= 600; i+=10) {
		glColor3f(0.0, i/600., 1.0-i/600.);
		glVertex2i(600-i, 0);
		glVertex2i(0, i);
	}
	glEnd();
	glBegin(GL_POLYGON);
	double angle, x, y;
	for (int i = 0; i <= 360; i += 10) {
		angle = i * PI / 180;
		x = cos(angle) * WINSIZE / 2 + WINSIZE / 2;
		y = sin(angle) * WINSIZE / 2 + WINSIZE / 2;
		glVertex2d(x, y);
	}

	glEnd();

	glFlush();

	FsPollDevice();
	while (FSKEY_NULL == FsInkey())
	{
		FsPollDevice();
		FsSleep(25);
	}

	return 0;
}