/*
24-780-B Engineering Computation Problem Set 7 - Bitmap Editor
Name: Zihao Ding
Andrew ID: zihaod
Date: 10/14/2018
Description:
The program realize a bitmap editor. 
The user can hover over the display and whenever a color number-code is hit, 
the pixel will be set to that color
Tips:
(0) Start the program and input width and height to start the window
(1) Use button 0-7 to set color of a pixel
(2) Hit button "c" to clean the window
(3) Hit button "l" and input the file name to load a bitmap
(4) Hit button "s" and input the file name to save a bitmap
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "fssimplewindow.h"
#include "CharBitmap_zihaod.h"

using namespace std;

int main(void)
{
	int key = NULL;
	int leftButton, middleButton, rightButton, locX, locY;
	int mouseEvent;
	int x, y;
	char color = '7';
	bool terminate = false;
	string filename;

	//input parameters
	int W, H;
	cout << "24-780 Engineering Computation Problem Set 7 - Bitmap Editor\n"
		<< "Tips: \n"
		<< "(0) Start the program and input width and height to start the window \n"
	    << "(1) Use button 0 - 7 to set color of a pixel \n"
		<< "(2) Hit button 'c' to clean the window \n"
		<< "(3) Hit button 'l' and input the file name to load a bitmap \n"
		<< "(4) Hit button 's' and input the file name to save a bitmap \n"
		<< "\n"
		<< "Enter the size of bitmap (reference value:16 16):";
	cin >> W >> H;

	CharBitmap bitmap;
	bitmap.create(W, H);
	bitmap.cleanUp();
	

	//open window
	FsOpenWindow(16, 16, 20*W, 20*H, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	while (! terminate)
	{
		FsPollDevice();
		key = FsInkey();

		//monitor mouse movement
		mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY);
		x = locX / 20;
		y = locY / 20;

		//monitor keyboard
		switch (key)
		{
			case FSKEY_0:
				color = '0';
				break;
			case FSKEY_1:
				color = '1';
				break;
			case FSKEY_2:
				color = '2';
				break;
			case FSKEY_3:
				color = '3';
				break;
			case FSKEY_4:
				color = '4';
				break;
			case FSKEY_5:
				color = '5';
				break;
			case FSKEY_6:
				color = '6';
				break;
			case FSKEY_7:
				color = '7';
				break;
			case FSKEY_ESC:
				terminate = true;
				break;
			case FSKEY_C:
				bitmap.cleanUp();
				break;
			case FSKEY_L:
				cout << "Please input the file name to load:";
				cin >> filename;
				bitmap.load(filename);
				filename = "";
				break;
			case FSKEY_S:
				cout << "Please input the file name to save:";
				cin >> filename;
				bitmap.save(filename);
				filename = "";
				break;
		}
		if (key && !terminate && x <= bitmap.width && y <= bitmap.height)
		{
			bitmap.setPixel(x,y,color);
		}

		bitmap.draw();
		
		FsSleep(10);
	}
	return 0;
}