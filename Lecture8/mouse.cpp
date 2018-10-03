#include <stdio.h>
#include <stdlib.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <string>

using namespace std;

int main(void)
{
	FsOpenWindow(0, 0, 800, 600, 1);

	string aMessage, bMessage;

	int leftButton, middleButton, rightButton, locX, locY;
	int mouseEvent;

	// while (true)
	for (;;)
	{
		FsPollDevice();
		auto key = FsInkey();

		mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY);

		if (key != FSKEY_NULL)
			break;   // exit loop

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		glRasterPos2i(100, 100);
		glColor3ub(255, 0, 255);
		YsGlDrawFontBitmap20x32("Move mouse around");

		glRasterPos2i(50, 200);
		glColor3ub(0, 0, 255);
		aMessage = "LeftDown: " + to_string(leftButton)
			+ " MiddleDown: " + to_string(middleButton)
			+ " RightDown: " + to_string(rightButton)
			+ " locX: " + to_string(locX) + " locY: " + to_string(locY);

		YsGlDrawFontBitmap7x10(aMessage.c_str());

		switch (mouseEvent)
		{
		case FSMOUSEEVENT_LBUTTONDOWN:
			bMessage = "Last Mouse Action: Left button was pressed";
			break;
		case FSMOUSEEVENT_LBUTTONUP:
			bMessage = "Last Mouse Action: Left button was released";
			break;
		case FSMOUSEEVENT_RBUTTONDOWN:
			bMessage = "Last Mouse Action: Right button was pressed";
			break;
		case FSMOUSEEVENT_RBUTTONUP:
			bMessage = "Last Mouse Action: Right button was released";
			break;
		case FSMOUSEEVENT_MOVE:
			bMessage = "Last Mouse Action: Mouse was moved";
			break;
		}

		glRasterPos2i(50, 400);
		glColor3ub(255, 0, 0);
		YsGlDrawFontBitmap7x10(bMessage.c_str());

		FsSwapBuffers();
	}

	return 0;
}