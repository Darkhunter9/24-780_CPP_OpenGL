#pragma once

#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "fssimplewindow.h"
#include "ysglfontdata.h"

struct intCoords 
{
	double x;
	double y;
};

struct Colorset
{
	int R;
	int G;
	int B;
};

struct Circle 
{
	double circleX;
	double circleY;
    int locX;
    int locY;
	Colorset colorset;
    Circle *next;
};

void DrawColorBar(Colorset colorset);

void PrintColor(Colorset colorset);

Colorset GetColor(int locX, int locY);

void DrawCircle(double circleX, double circleY, int locX, int locY, Colorset colorset);

void pushCircle(double circleX, double circleY, int locX, int locY, Colorset colorset, Circle *&head);

void DrawShape(Circle *head);

Circle *popCircle(Circle *&head);

bool InTriangle(int locX, int locY);