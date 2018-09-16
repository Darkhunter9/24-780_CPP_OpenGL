/*
24-780-B Engineering Computation Problem Set 3 - Spring-mass system drawing
Name: Zihao Ding
Andrew ID: zihaod
Date: 09/16/2018
Description:
The program shows a schematic drawing of a mass-spring system, with animation of bounding/rebounding.
*/

#include <stdio.h>
#include "fssimplewindow.h"
#include "springMass_zihaod.h"

intCoords getScreenCoords(double modelX, double modelY)
{
	intCoords point;
	point.x = 100+modelX;
	point.y = 300-modelY;
	return point;
}

void screenVertex(double modelX, double modelY)
{
	intCoords point = getScreenCoords(modelX, modelY);
	glVertex2d(point.x, point.y);

}

void drawWall(void)
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2d(100, 0);
	glVertex2d(100, 600);
	glEnd();

	for (int i = 0; i < 600; i+=10)
	{
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex2d(100, i);
		glVertex2d(80, i+20);
		glEnd();
	}
}

void drawMass(double locationX, double height)
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	screenVertex(locationX,height*0.5);
	screenVertex(locationX,-height*0.5);
	screenVertex(locationX+height,-height*0.5);
	screenVertex(locationX+height,height*0.5);
	glEnd();
}

void drawSpring(double length, double height)
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	screenVertex(0, 0);
	screenVertex(length/3, 0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	screenVertex(length*2/3, 0);
	screenVertex(length, 0);
	glEnd();

	for (int i = 0; i < 7; i++)
	{
		if (i == 0 || i ==6)
		{
			if (i == 0)
			{
				glColor3f(0.0, 0.0, 1.0);
				glBegin(GL_LINES);
				screenVertex(length/3, 0);
				screenVertex(length/3+length/36, -height/2);
				glEnd();
			}
			else
			{
				glColor3f(0.0, 0.0, 1.0);
				glBegin(GL_LINES);
				screenVertex(length*2/3, 0);
				screenVertex(length*2/3-length/36, height/2);
				glEnd();
			}
		}
		else
		{
			if (i%2 != 0)
			{
				glColor3f(0.0, 0.0, 1.0);
				glBegin(GL_LINES);
				screenVertex(length/3+(2*i-1)*length/36, -height/2);
				screenVertex(length/3+(2*i+1)*length/36, height/2);
				glEnd();
			}
			else
			{
				glColor3f(0.0, 0.0, 1.0);
				glBegin(GL_LINES);
				screenVertex(length/3+(2*i+1)*length/36, -height/2);
				screenVertex(length/3+(2*i-1)*length/36, height/2);
				glEnd();
			}
		}
	}
}