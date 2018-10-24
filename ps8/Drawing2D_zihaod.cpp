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
#include "Drawing2D_zihaod.h"

using namespace std;

Drawing2D::Drawing2D()
{
	
}

Drawing2D::~Drawing2D()
{

}

void Drawing2D::readFile(const string fName)
{
	string s = "";

	ifstream inFile;
	inFile.open(fName);
	if (inFile.is_open())
	{
		while (!inFile.eof() && getline(inFile, s))
		{
			Line2D temp;
			temp.makeFromString(s);
			Line.push_back(temp);
			s = "";
		}
		inFile.close();
	}
}

void Drawing2D::draw()
{
	for (int i = 0; i < Line.size(); i++)
	{
		Line[i].draw();
	}
}

void Drawing2D::clear()
{
	Line.clear();
}

void Drawing2D::adjustZoom(const double locX, const double locY, const double newScaleFactor)
{
	if (Scale*newScaleFactor >= 1)
	{
		double newScale = Scale * newScaleFactor;
		for (int i = 0; i < Line.size(); i++)
		{
			Line[i].adjustZoom(locX, locY, newScaleFactor);
		}
		Scale = newScale;
	}
}

void Drawing2D::pan(const int locX, const int locY, const int prevLocX, const int prevLocY)
{
	for (int i = 0; i < Line.size(); i++)
	{
		Line[i].pan(locX, locY, prevLocX, prevLocY);
	}
}