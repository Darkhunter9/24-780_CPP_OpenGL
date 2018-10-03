#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "ps05_zihaod.h"

using namespace std;
const double PI = 3.1415927;

intCoords getScreenCoords(double modelX, double modelY)
{
	intCoords point;
	point.x = modelX;
	point.y = 600 - modelY;
	return point;
}

void screenVertex(double modelX, double modelY)
{
	intCoords point = getScreenCoords(modelX, modelY);
	glVertex2d(point.x, point.y);
}

void DrawColorBar(Colorset colorset)
{
    /*
    glShadeModel(GL_SMOOTH);

    glBegin(GL_QUADS);

    glColor3ub(255,0,0);
    screenVertex(720,600);

    glColor3ub(0,255,0);
    screenVertex(800,600);

    glColor3ub(0,0,255);
    screenVertex(800,520);

    glColor3ub(255,255,0);
    screenVertex(720,520);

    glColor3ub(colorset.R,colorset.G,colorset.B);
    glEnd();
    */

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);

	glColor3ub(255,0,0);
	glVertex2d(760, 10);

    glColor3ub(0,255,0);
	glVertex2d(760-pow(3,0.5)*15, 55);

    glColor3ub(0,0,255);
	glVertex2d(760+pow(3,0.5)*15, 55);

	glColor3ub(colorset.R,colorset.G,colorset.B);
    glEnd();
}

double Area(double l1, double l2, double l3)
{
    double p = (l1+l2+l3)/2;
    return pow(p*(p-l1)*(p-l2)*(p-l3),0.5);
}

bool InTriangle(int locX, int locY)
{
    double distance1 = locX - 760;
    double distance2 = pow(3, -0.5) * (locY - 10);
    if (distance1 <= distance2 && distance1 >= -distance2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Colorset GetColor(int locX, int locY)
{
    /*
    Colorset colorset;
    colorset.R = 0;
    colorset.G = 250;
    colorset.B = 0;
    return colorset;
    */
    double lR = pow(pow(760.0 - locX, 2) + pow(10.0 - locY, 2), 0.5);
    double lG = pow(pow(760.0 - pow(3,0.5)*15 - locX, 2) + pow(55.0 - locY, 2), 0.5);
    double lB = pow(pow(760.0 + pow(3,0.5)*15 - locX, 2) + pow(55.0 - locY, 2), 0.5);
    double sR = Area(lG, lB, pow(3, 0.5) * 30);
    double sG = Area(lR, lB, pow(3, 0.5) * 30);
    double sB = Area(lR, lG, pow(3, 0.5) * 30);

    Colorset colorset;
    colorset.R = (int)(sR/(pow(3, 0.5)/4*pow(pow(3, 0.5) * 30,2))*255);
    colorset.G = (int)(sG/(pow(3, 0.5)/4*pow(pow(3, 0.5) * 30,2))*255);
    colorset.B = (int)(sB/(pow(3, 0.5)/4*pow(pow(3, 0.5) * 30,2))*255);
    return colorset;
}

void PrintColor(Colorset colorset)
{ 
    auto s1 = to_string(colorset.R);
    auto s2 = to_string(colorset.G);
    auto s3 = to_string(colorset.B);
    string s = "The color you choose is: R" + s1 + " G" + s2 + " B" + s3;
    glRasterPos2i(5, 20);
    glColor3ub(colorset.R,colorset.G,colorset.B);
    YsGlDrawFontBitmap12x16(s.c_str());
    
}

void DrawCircle(double circleX, double circleY, int locX, int locY, Colorset colorset)
{
    glColor3ub(colorset.R,colorset.G,colorset.B);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 64; i++) 
	{
		double angle = (double)i * PI / 32.0;
        double R = pow((pow(circleX-locX,2)+pow(circleY-locY,2)),0.5);
        double x = (double)circleX + cos(angle)*R;
		double y = (double)circleY + sin(angle)*R;
		glVertex2d(x, y);
	}
	glEnd();
}

void pushCircle(double circleX, double circleY, int locX, int locY, Colorset colorset, Circle *&head)
{
	Circle *newCircle = new Circle;
	newCircle->circleX = circleX;
	newCircle->circleY = circleY;
    newCircle->locX = locX;
    newCircle->locY = locY;
    newCircle->colorset = colorset;
    newCircle->next = head;

	head = newCircle;
}

Circle *popCircle(Circle *&head)
{
	Circle *poppedCircle = head;
	if (poppedCircle != NULL)
		head = poppedCircle->next;

	return poppedCircle;
}

void DrawShape(Circle *head)
{
	Circle *currCircle = head;
    while (currCircle != NULL)
    {
        DrawCircle(currCircle->circleX,currCircle->circleY,currCircle->locX,currCircle->locY,currCircle->colorset);
        currCircle = currCircle->next;
    }
}

