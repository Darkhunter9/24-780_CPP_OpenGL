/*
24-780-B Engineering Computation Problem Set 6-2 - Animate spring mass
Name: Zihao Ding
Andrew ID: zihaod
Date: 10/07/2018
Description:
The program shows a schematic drawing of a mass-spring system, with animation of bounding/rebounding.
*/

#include <stdio.h>
#include "fssimplewindow.h"
#pragma once

struct intCoords {
	double x;
	double y;
};

// converts model coordinates to screen coordinates
intCoords getScreenCoords(double modelX, double modelY);

// given some model coordinates, function adds a new vertex2di
// makes use of getScreenCoords();
void screenVertex(double modelX, double modelY);

// draws the geometry that represents the wall, given a model
// coordinate for the horz location and model scale height
//void drawWall(double locationX, double height);
void drawWall(void);

// draws the box (chamfered) that represents the mass
// requires model location for the left-most point on box
// and the height of the box
void drawMass(double locationX, double height);

// draws a spring with some coils, given length and height
// in model coordinates
void drawSpring(double length, double height);