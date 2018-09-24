#include <stdio.h>
#include "fssimplewindow.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "cannon_zihaod.h"

const double PI = 3.1415927;

obstacle ProduceObstacle(void)
{
	obstacle tempobstacle;
	tempobstacle.x = rand() % 80;
	tempobstacle.y = rand() % 60;
	tempobstacle.w = rand() % 8;
	tempobstacle.h = rand() % 15;
	tempobstacle.hit = false;
	return tempobstacle;
}

intCoords getScreenCoords(double modelX, double modelY)
{
	intCoords point;
	point.x = modelX*10;
	point.y = 600 - modelY*10;
	return point;
}

void screenVertex(double modelX, double modelY)
{
	intCoords point = getScreenCoords(modelX, modelY);
	glVertex2d(point.x, point.y);
}

void DrawObstacle(obstacle Obstacle)
{
	if (! Obstacle.hit)
	{
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_QUADS);
		screenVertex(Obstacle.x-0.5*Obstacle.w, Obstacle.y-0.5*Obstacle.h);
		screenVertex(Obstacle.x+0.5*Obstacle.w, Obstacle.y-0.5*Obstacle.h);
		screenVertex(Obstacle.x+0.5*Obstacle.w, Obstacle.y+0.5*Obstacle.h);
		screenVertex(Obstacle.x-0.5*Obstacle.w, Obstacle.y+0.5*Obstacle.h);
		glEnd();
	}
}

void UpdateTarget(obstacle &Target)
{
	if (!Target.hit)
	{
		//The change of coordinate y
		if (Target.y == 5)
		{
			Target.y = 60;
		}
		else
		{
			Target.y -= 0.25;
		}

		//draw target

		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		screenVertex(Target.x - 0.5*Target.w, Target.y - 0.5*Target.h);
		screenVertex(Target.x + 0.5*Target.w, Target.y - 0.5*Target.h);
		screenVertex(Target.x + 0.5*Target.w, Target.y + 0.5*Target.h);
		screenVertex(Target.x - 0.5*Target.w, Target.y + 0.5*Target.h);
		glEnd();
	}
}

void UpdatePlayer(double playerX, double playerY, double angle)
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	screenVertex(playerX, playerY);
	screenVertex(playerX + 2 * cos(angle / 180 * PI), playerY + 2 * sin(angle / 180 * PI));
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	screenVertex(playerX - 1, playerY - 1);
	screenVertex(playerX + 1, playerY - 1);
	screenVertex(playerX + 1, playerY + 1);
	screenVertex(playerX - 1, playerY + 1);
	glEnd();	
}

void UpdateMissile(int &missileTime, double &missileX0, double &missileY0, double &missileX, double &missileY, double &velocity, double &angle)
{
	missileX = missileX0 + (double)missileTime / 1000 * velocity * cos(angle / 180 * PI);
	missileY = missileY0 + (double)missileTime / 1000 * velocity * sin(angle / 180 * PI) - 0.5 * 10 * pow((double)missileTime / 1000, 2);

	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++) 
	{
		double angle2 = (double)i * PI / 32.0;
		double x = (double)missileX + cos(angle2)*0.5;
		double y = (double)missileY + sin(angle2)*0.5;
		screenVertex(x, y);
	}
	glEnd();
}

bool CheckHit(double missileX, double missileY, obstacle point)
{
	if (missileX >= point.x - 0.5*point.w - 0.5 &&
		missileX <= point.x + 0.5*point.w + 0.5 &&
		missileY >= point.y - 0.5*point.h - 0.5 &&
		missileY <= point.y + 0.5*point.h + 0.5)
	{
		return true;
	}
	else
	{
		return false;
	}
}