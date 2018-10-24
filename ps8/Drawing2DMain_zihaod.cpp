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
(3) Hold middle button and mouse move to move the drawing
(4) Hit key 'SPACE' to reset the picture position
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "fssimplewindow.h"
#include "Drawing2D_zihaod.h"
#include "Line2D_zihaod.h"

using namespace std;

int main(void)
{
	int key = NULL;
	int leftButton, middleButton, rightButton, locX, locY;
	int prevLocX, prevLocY;
	int mouseEvent;
	bool terminate = false;
	string filename;

	//input parameters
	cout << "24-780 Engineering Computation Problem Set 8 - Line Drawing\n"
		<< "Tips: \n"
		<< "(0) Start the program and input the name of data file\n"
		<< "(1) Use 'ESC' to exit the program \n"
		<< "(2) Use wheel up/down to zoom in/out \n"
		<< "(3) Hold middle button and mouse move to move the drawing \n"
		<< "(4) Hit key 'SPACE' to reset the picture position \n"
		<< "\n"
		<< "Please input the name of data file (max length 255):";
	cin >> filename;
	while (filename.size() == 0 || filename.size() > 255 )
	{
		filename = "";
		cout << "The length of filename should be 1~255!\n"
			<< "Please re-enter the name of data file:";
		cin >> filename;
	}

	//initialize class
	Drawing2D linemap;
	linemap.readFile(filename);

	//open window
	FsOpenWindow(16, 16, 800, 600, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY);

	while (!terminate)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		FsPollDevice();
		key = FsInkey();

		//monitor mouse movement
		mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY);
		//realize pan
		if (middleButton) 
		{   // execute pan when middle button is held down
			linemap.pan(locX, locY, prevLocX, prevLocY);
		}
		prevLocX = locX; prevLocY = locY;   // needed so that pan feature does not "jump"

		//monitor keyboard
		switch (key)
		{
			case FSKEY_ESC:
				terminate = true;
				break;
			case FSKEY_WHEELUP: //cout << "Detected wheel UP event" << endl;
				linemap.adjustZoom(locX, locY, 1.1);
				break;
			case FSKEY_WHEELDOWN: //cout << "Detected wheel DOWN event" << endl;
				linemap.adjustZoom(locX, locY, 1. / 1.1);
				break;
			case FSKEY_SPACE:
				linemap.clear();
				linemap.readFile(filename);
		}

		linemap.draw();

		FsSwapBuffers();
		FsSleep(25);
	}
	return 0;
}