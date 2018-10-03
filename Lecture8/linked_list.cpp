#include <stdio.h>
#include <stdlib.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"

using namespace std;

struct point {
	double xCoord;
	double yCoord;
	point *next;
};

void pushPoint(double x, double y, point *&head)
{ // need * and ampersand to accomplish call by reference

	point *newPoint = new point;
	newPoint->xCoord = x;
	newPoint->yCoord = y;
	newPoint->next = head;

	head = newPoint;
}

point *popPoint(point *&head)
{
	point *poppedPoint = head;
	if (poppedPoint != NULL)
		head = poppedPoint->next;

	return poppedPoint;
}

void drawShape(point *head)
{
	point *currPoint = head;
	glBegin(GL_LINE_STRIP);
	while (currPoint != NULL) {
		glVertex2d(currPoint->xCoord, currPoint->yCoord);
		currPoint = currPoint->next;
	}
	glEnd();
}

int main(void)
{
	FsOpenWindow(0, 0, 800, 600, 1);

	int leftButton, middleButton, rightButton, locX, locY;
	int mouseEvent;
	point *shape1 = NULL;
	point *shape2 = NULL;
	point **currShape = &shape1;

	while (true)
	{
		FsPollDevice();
		auto key = FsInkey();

		mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY);
		if (key == FSKEY_BS)
			popPoint(*currShape);
		else if (key != FSKEY_NULL)
			break;   // exit loop

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		glRasterPos2i(1, 12);
		glColor3ub(255, 0, 255);
		YsGlDrawFontBitmap7x10("Click to draw (left or right mouse button), BKSP to erase, ESC to exit.");

		glColor3ub(255, 0, 0);
		glLineWidth(3.);
		drawShape(shape1);

		glColor3ub(180, 50, 100);
		glLineWidth(6.);
		drawShape(shape2);

		switch (mouseEvent)
		{
		case FSMOUSEEVENT_LBUTTONDOWN:
			pushPoint(locX, locY, shape1);
			currShape = &shape1;
			break;
		case FSMOUSEEVENT_RBUTTONDOWN:
			pushPoint(locX, locY, shape2);
			currShape = &shape2;
			break;
		}

		FsSwapBuffers();
		FsSleep(10);

	}

	return 0;
}