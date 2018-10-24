/*
24-780 Engineering Computation Problem Set 8 - Line Drawing
Name: Zihao Ding
Andrew ID: zihaod
Date: 10/20/2018
Description:
The program realize a line drawing map.
The user can load the file to realize line drawing, and use mouse to zoom in/out,
and move the figure.
Tips:
(0) Start the program and input the name of data file
(1) Use 'ESC' to exit the program
(2) Use wheel up/down to zoom in/out
(3) Use middle button and mouse move to move the drawing
(4) Hit key 'SPACE' to reset the picture position
*/

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "fssimplewindow.h"
#include "Line2D_zihaod.h"

using namespace std;

Line2D::Line2D()
{
	X1 = 0;
	Y1 = 0;
	X2 = 0;
	Y2 = 0;
	R = 0;
	G = 0;
	B = 0;
}


Line2D::~Line2D()
{

}

void Line2D::draw()
{
	glColor3ub(R, G, B);
	glBegin(GL_LINES);
	glVertex2d(X1, 600-Y1);
	glVertex2d(X2, 600-Y2);
	glEnd();
}

void Line2D::makeFromString(const string info)
{
	stringstream s(info);
	s >> X1;
	s >> Y1;
	s >> X2;
	s >> Y2;
	s >> R;
	s >> G;
	s >> B;
}

void Line2D::adjustZoom(const double locX, const double locY, const double newScaleFactor)
{
	double newScale = Scale * newScaleFactor;
	X1 = (int)round((locX * (Scale - newScale)
		+ X1 * newScale) / Scale);
	X2 = (int)round((locX * (Scale - newScale)
		+ X2 * newScale) / Scale);
	Y1 = (int)round((locY * (Scale - newScale)
		+ Y1 * newScale) / Scale);
	Y2 = (int)round((locY * (Scale - newScale)
		+ Y2 * newScale) / Scale);;
	Scale = newScale;
}

void Line2D::pan(const int locX, const int locY, const int prevLocX, const int prevLocY)
{
	X1 += (locX - prevLocX);
	X2 += (locX - prevLocX);
	Y1 -= (locY - prevLocY);
	Y2 -= (locY - prevLocY);
}