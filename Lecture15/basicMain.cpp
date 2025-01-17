#include <stdio.h>
#include <math.h>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "CameraObject.h"

//const double YsPi = 3.1415927;

int main(void)
{
	int terminate = 0;
	CameraObject camera;

	camera.z = 10.0;

	FsOpenWindow(16, 16, 800, 600, 1);

	while (0 == terminate)
	{
		FsPollDevice();

		int wid, hei;
		FsGetWindowSize(wid, hei);

		int key = FsInkey();
		switch (key)
		{
		case FSKEY_ESC:
			terminate = 1;
			break;
		}
		glClear(GL_DEPTH_BUFFER_BIT |
			GL_COLOR_BUFFER_BIT);

		glViewport(0, 0, wid, hei);

		// Set up 3D drawing
		camera.SetUpCameraProjection();
		camera.SetUpCameraTransformation();

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(1, 1);

		// 3D drawing from here


		// Set up 2D drawing
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, (float)wid - 1, (float)hei - 1, 0, -1, 1);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glDisable(GL_DEPTH_TEST);

		FsSwapBuffers();
		FsSleep(10);
	}

	return 0;
}
