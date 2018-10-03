#include <stdio.h>
#include <stdlib.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"

int main()
{
	FsOpenWindow(0, 0, 800, 600, 1);

	for (;;)   // this will loop forever
	{
		FsPollDevice();
		auto key = FsInkey();

		if (key != FSKEY_NULL)
			break;

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		glRasterPos2i(100, 100);  // sets position
		glColor3ub(0, 0, 255);
		YsGlDrawFontBitmap20x32("Test Message");

		FsSwapBuffers();
	}

	return 0;
}