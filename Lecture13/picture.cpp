// Pictures in OpenGL (event-driven)

#include <stdio.h>
#include "yspng.h"
#include "fssimplewindow.h"

void render(void *input)
{
	YsRawPngDecoder *png = (YsRawPngDecoder *)input;
	int winWid, winHei;

	FsGetWindowSize(winWid, winHei);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRasterPos2d(0.0, (double)(winHei - 1));

	glDrawPixels(png->wid, png->hei, GL_RGBA, GL_UNSIGNED_BYTE, png->rgba);

	FsSwapBuffers();
}

int main(void)
{

	YsRawPngDecoder png;
	if (YSOK == png.Decode("Hippos01.png")) {
		printf("Read Width=%d Height=%d\n", png.wid, png.hei);
		png.Flip();
	}
	else {
		printf("Read Error!\n");
		return 0;
	}

	FsOpenWindow(16, 16, png.wid, png.hei, 1);

	// set up the call back function with the object
	FsRegisterOnPaintCallBack(render, &png);

	int key = FSKEY_NULL;
	while (FSKEY_ESC != key)
	{
		FsPollDevice();
		key = FsInkey();

		//glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		//int winWid, winHei;
		//FsGetWindowSize(winWid, winHei);
		//glRasterPos2d(0.0, (double)(winHei - 1));
		//glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
		//FsSwapBuffers();

		FsPushOnPaintEvent();

		FsSleep(50);
	}
	return 0;
}