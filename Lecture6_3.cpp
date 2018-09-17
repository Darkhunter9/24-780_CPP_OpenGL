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

void drawMissile(int x, int y)
{
	glColor3ub(255, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x, y + 14);
	glEnd();
}

int main()
{
	FsOpenWindow(16, 16, 800, 600, 1);

	bool terminate = false;
	int playerX = 400, playerY = 580;
	bool missileVisible = false;
	int missileX = 0, missileY = 0;

	while (!terminate)
	{
		FsPollDevice();
		int key = FsInkey();

		switch (key) {
		case FSKEY_ESC:
			terminate = true;
			break;
		case FSKEY_LEFT:
			playerX -= 10;
			break;
		case FSKEY_RIGHT:
			playerX += 10;
			break;
		case FSKEY_SPACE:
			if (!missileVisible)
			{
				missileVisible = true;
				missileX = playerX;
				missileY = playerY;
			}
			break;
		}
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		drawPlayer(playerX, playerY);

		if (missileVisible)
		{
			missileY -= 10;
			if (missileY < 0)
				missileVisible = false;
			drawMissile(missileX, missileY);
		}

		FsSwapBuffers();
		FsSleep(20);
	}

	return 0;
}