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
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "fssimplewindow.h"
#include "CharBitmap_zihaod.h"

using namespace std;

CharBitmap::CharBitmap()
{
}

CharBitmap::~CharBitmap()
{
}

void CharBitmap::create(int w, int h) // initializes object with given dimensions
{
	width = w;
	height = h;
	pixels = new char[width*height];
}

void CharBitmap::cleanUp() // used to reset and free up all space used by object
{
	for (int i = 0; i < width*height; i++)
	{
		pixels[i] = '7';
	}
}

void CharBitmap::setPixel(int x, int y, unsigned char p) // sets the pixel value
{
	pixels[y * width + x] = p;
}

char CharBitmap::getPixel(int x, int y) const // returns the value/color of the pixel
{
	return pixels[y * width + x];
}

void CharBitmap::draw() const // draw the bitmap, magnified (use GL_QUADS) and colors defined in pixels array.
{
	for (int i = 0; i < width*height; i++)
	{
		switch (pixels[i])
		{
		case '0':
			glColor3ub(0, 0, 0);
			break;
		case '1':
			glColor3ub(0, 0, 255);
			break;
		case '2':
			glColor3ub(255, 0, 0);
			break;
		case '3':
			glColor3ub(255, 0, 255);
			break;
		case '4':
			glColor3ub(0, 255, 0);
			break;
		case '5':
			glColor3ub(0, 255, 255);
			break;
		case '6':
			glColor3ub(255, 255, 0);
			break;
		case '7':
			glColor3ub(255, 255, 255);
			break;
		}
		
		int x = i % width;
		int y = i / width;
		glBegin(GL_QUADS);
		glVertex2i(x*20, y*20);
		glVertex2i((x+1)*20, y*20);
		glVertex2i((x+1)*20, (y+1)*20);
		glVertex2i(x*20, (y+1)*20);
		glEnd();
	}
	FsSwapBuffers();
}


void CharBitmap::load(const string fName) // load a bitmap from a file
{
	ifstream inFile;
	int line = 0;
	string s;
	string number = "";

	inFile.open(fName);
	if (inFile.is_open()) // may not have found file
	{ 
		while (!inFile.eof() && getline(inFile,s)) 
		{
			if (line == 0)
			{	
				int i = 0;
				while (i < s.size())
				{
					if (s[i] != ' ')
					{
						number += s[i];
					}
					else
					{
						width = atoi(number.c_str());
						number = "";
					}
					i++;
				}
				height = atoi(number.c_str());
				create(width,height);
			}
			else
			{
				for (int i = 0; i < s.size(); i++)
				{
					pixels[(line-1)*width+i] = s[i];
				}
			}
			line += 1;
		}
		inFile.close();
	}
}

void CharBitmap::save(const string fName) const // save a bitmap to a file
{
	ofstream outFile;
	outFile.open(fName);
	if (outFile.is_open())
	{
		outFile << width << " " << height << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				outFile << pixels[i*width+j];
			}
			outFile << endl;
		}
	}
	outFile.close();
}
