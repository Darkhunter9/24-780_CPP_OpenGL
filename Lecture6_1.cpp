#include <stdio.h>
#include <math.h>
#include "fssimplewindow.h"

void drawPlayer(int x, int y)
{
	int bSize = 10;

	glColor3ub(0, 255, 0);
	glBegin(GL_QUADS);

	// vertical rectangle
	glVertex2i(x - bSize / 2, y - 2 * bSize + 1);
	glVertex2i(x + bSize / 2 - 1, y - 2 * bSize + 1);
	glVertex2i(x + bSize / 2 - 1, y);
	glVertex2i(x - bSize / 2, y);

	// base rectangle
	glVertex2i(x - bSize * 1.5, y - bSize + 1);
	glVertex2i(x + bSize * 1.5 - 1, y - bSize + 1);
	glVertex2i(x + bSize * 1.5 - 1, y);
	glVertex2i(x - bSize * 1.5, y);
	glEnd();
}

int main(void)
{
	FsOpenWindow(16, 16, 800, 600, 1);  // note the "1" for double buffering
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	drawPlayer(300,580);
	//glFlush();   // not using since we are double buffering
	FsSwapBuffers();
	while (FSKEY_NULL == FsInkey()) {
		FsPollDevice();
		FsSleep(25);
	}	
}