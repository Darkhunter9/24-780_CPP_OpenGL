#include <stdio.h>
#include "fssimplewindow.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "cannon_zihaod.h"

int main()
{
	bool terminate = false;
	int key;

	FsOpenWindow(16, 16, 800, 600, 1);

	
	srand(time(NULL));
	
	//initial the target
	obstacle Target;
	Target.x = 75;
	Target.y = 60;
	Target.w = 5;
	Target.h = 5;
	Target.hit = false;

	//initial five rectangular obstacles at random locations
	//The width and height of each obstacle should range between 8m and 15m, randomly selected.
	obstacle ObstacleList[5];
	for (int i = 0; i < 5; i++)
	{
		ObstacleList[i] = ProduceObstacle();
	}

	//initial the player
	double playerX = 5;
	double playerY = 5;
	double stepSize = 5;
	double angle = 45;
	double angle_current = 45;

	//initial the missle
	bool missileVisible = false;
	double missileX, missileY;
	double missileX0, missileY0;
	double velocity = 30;
	int missileTime = 0;

	while (! terminate)
	{
		FsPollDevice();
		key = FsInkey();

		switch (key) 
		{
			case FSKEY_ESC:
				terminate = true;
				break;
			case FSKEY_UP:
				playerY += stepSize;
				if (playerY > 59)
					playerY = 59;
				break;
			case FSKEY_DOWN:
				playerY -= stepSize;
				if (playerY < 1)
					playerY = 1;
				break;
			case FSKEY_LEFT:
				angle += 2*stepSize;
				if (angle > 135)
					angle = 135;
				break;
			case FSKEY_RIGHT:
				angle -= 2*stepSize;
				if (angle < 45)
					angle = 45;
				break;
			case FSKEY_SPACE:
				if (!missileVisible) 
				{
					missileVisible = true;
					missileX = playerX;
					missileY = playerY;
					missileX0 = playerX;
					missileY0 = playerY;
					missileTime = 0;
					angle_current = angle;
				}
				break;
		}

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		//draw player
		UpdatePlayer(playerX, playerY, angle);

		//draw obstacle
		for (int i = 0; i < 5; i++)
		{
			DrawObstacle(ObstacleList[i]);
		}

		//draw target
		UpdateTarget(Target);
		
		//update missile
		if (missileVisible)
		{
			//draw and move missile
			UpdateMissile(missileTime, missileX0, missileY0, missileX, missileY, velocity, angle_current);
			missileTime += 25;

			//check for missile hit
			if ((missileX < 0) | (missileX > 80) | (missileY > 60) | (missileY < 0))
			{
				missileVisible = false;
			}
			else
			{
				//hit the obstacle
				for (int i = 0; i < 5; i++)
				{	
					if (missileVisible && !ObstacleList[i].hit && CheckHit(missileX, missileY, ObstacleList[i]))
					{
						ObstacleList[i].hit = true;
						missileVisible = false;
					}
				}

				//hit the target
				if (missileVisible && !Target.hit && CheckHit(missileX, missileY, Target))
				{
					terminate = true;
				}
			}
		}

		FsSwapBuffers();
		FsSleep(25);
	}

	return 0;
}