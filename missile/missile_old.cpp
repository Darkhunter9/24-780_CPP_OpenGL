#include <stdio.h>
#include "fssimplewindow.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

void drawPlayer(int x, int y)
{
	int bSize = 20;

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
	glLineWidth(4.);
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x, y + 14);
	glEnd();
}

void drawTarget(int x, int y, int sizeX, int sizeY)
{
	glColor3ub(0, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x + sizeX, y);
	glVertex2i(x + sizeX, y + sizeY);
	glVertex2i(x, y + sizeY);
	glEnd();
}

void moveTarget(int &x, int &y, int scrnSizeX, int scrnSizeY, int speed = 6)
{
	x += speed;
	if (x > scrnSizeX)
		x = 0;
}

bool targetIsHit(int missileX, int missileY, int targetX,
	int targetY, int targetSizeX, int targetSizeY)
{
	int relativeX, relativeY;
	relativeX = missileX - targetX;
	relativeY = missileY - targetY;

	return (0 <= relativeX && relativeX <= targetSizeX
		&& 0 <= relativeY && relativeY <= targetSizeY);
}

int main()
{

	bool terminate = false;
	int stepSize = 10;
	int playerX = 400, playerY = 580;
	int key;
	bool missileVisible = false;
	int missileX, missileY;

	int targetX[20], targetY[20], targetSizeX[20], targetSizeY[20], targetSpeed[20];
	bool targetAlive[20];
	const int numbOfTargets = 7;
	int numbOfLiveTargets;

	FsOpenWindow(16, 16, 800, 600, 1);

	// initialize targets
	srand(time(NULL));
	numbOfLiveTargets = numbOfTargets;
	for (int i = 0; i < numbOfTargets; i++) {
		targetX[i] = rand() % 800;
		targetY[i] = rand() % 500;
		targetSizeX[i] = rand() % (200 - 20) + 20;
		targetSizeY[i] = rand() % (30 - 5) + 5;
		targetSpeed[i] = rand() % (10 - 2) + 2;
		targetAlive[i] = true;
	}

	while (!terminate) {
		FsPollDevice();
		key = FsInkey();

		switch (key) {
		case FSKEY_ESC:
			terminate = true;
			break;
		case FSKEY_LEFT:
			playerX -= stepSize;
			if (playerX < 0)
				playerX = 0;
			break;
		case FSKEY_RIGHT:
			playerX += stepSize;
			if (playerX > 800)
				playerX = 800;
			break;
		case FSKEY_SPACE:
			if (!missileVisible) {
				missileVisible = true;
				missileX = playerX;
				missileY = playerY;
			}
			break;
		}

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		if (missileVisible) {
			//draw and move missile
			drawMissile(missileX, missileY);
			missileY -= 9;
			if (missileY < 0)
				missileVisible = false;

			//check for missile hit
			for (int i = 0; i < numbOfTargets; i++) {
				if (targetAlive[i] && targetIsHit(missileX, missileY, targetX[i],
					targetY[i], targetSizeX[i], targetSizeY[i])) {
					targetAlive[i] = false;
					//missileVisible = false;
					numbOfLiveTargets--;
				}
			}
			terminate = (numbOfLiveTargets <= 0);
		}

		for (int i = 0; i < numbOfTargets; i++) {
			if (targetAlive[i]) {
				drawTarget(targetX[i], targetY[i], targetSizeX[i], targetSizeY[i]);
				moveTarget(targetX[i], targetY[i], 800, 600, targetSpeed[i]);
			}
		}
		drawPlayer(playerX, playerY);
		FsSwapBuffers();
		FsSleep(20);
	}

	return 0;
}