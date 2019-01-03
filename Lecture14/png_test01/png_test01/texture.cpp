#include <stdio.h>
#include "yspng.h"
#include "fssimplewindow.h"
#include <math.h>
#include <ctype.h>

const double PI=3.1415927;

int main(void)
{

    YsRawPngDecoder png[2];
	png[0].Decode("Hippos01.png");
	png[1].Decode("imagesample1.png");

    FsOpenWindow(16,16,800,600,1);

    GLuint texId[2];  // this will be use as texture identifiers for the two PNGs

    // glGenTextures(2,texId);  // You can also reserve two texture identifies with one call this way.

    glGenTextures(1,&texId[0]);  // Reserve one texture identifier
    glBindTexture(GL_TEXTURE_2D,texId[0]);  // Making the texture identifier current (or bring it to the deck)

	// set up parameters for the current texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    glTexImage2D
        (GL_TEXTURE_2D,
         0,    // Level of detail
         GL_RGBA,
         png[0].wid,
         png[0].hei,
         0,    // Border width, but not supported and needs to be 0.
         GL_RGBA,
         GL_UNSIGNED_BYTE,
         png[0].rgba);

    glGenTextures(1,&texId[1]);  // Reserve texture identifier for other PNG
    glBindTexture(GL_TEXTURE_2D,texId[1]);  // Making the texture identifier current (or bring it to the deck)

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    glTexImage2D
        (GL_TEXTURE_2D,
         0,
         GL_RGBA,
         png[1].wid,
         png[1].hei,
         0,
         GL_RGBA,
         GL_UNSIGNED_BYTE,
         png[1].rgba);

    double angle=0.0;

    int key=FSKEY_NULL;
    while(FSKEY_ESC!=key)
    {
        FsPollDevice();

        key=FsInkey();

        int wid,hei;
        FsGetWindowSize(wid,hei);

        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

		// in order for textures to show, you must create a projection
        glViewport(0,0,wid,hei);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,(float)wid-1,(float)hei-1,0,-1,1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
        glColor4d(1.0,1.0,1.0,1.0);

		// enable texture mapping
        glEnable(GL_TEXTURE_2D);

		// bind a texture to OpenGL primitives
		glBindTexture(GL_TEXTURE_2D, texId[1]);

		glBegin(GL_QUADS);

		// For each vertex, assign texture coordinate before vertex coordinate.
		glTexCoord2d(0.0, 0.0);
		glVertex2i(0, 0); 

		glTexCoord2d(1.0, 0.0);
		glVertex2i(200, 0);

		glTexCoord2d(1.0, 1.0);
		glVertex2i(400, 400);

		glTexCoord2d(0.0, 1.0);
		glVertex2i(0, 400);

		glEnd();

		// bind the other texture
        glBindTexture(GL_TEXTURE_2D,texId[0]);

        glBegin(GL_QUADS);  // this one a tilted rectangle that we'll cause to spin

		// For each vertex, assign texture coordinate before vertex coordinate.
        glTexCoord2d(0.0,0.0);   
        glVertex2d(400.0+200.0*cos(angle),300.0-200.0*sin(angle));

        glTexCoord2d(1.0,0.0);
        glVertex2d(400.0+200.0*cos(angle+PI/2.0),300.0-200.0*sin(angle+PI/2.0));

        glTexCoord2d(1.0,1.0);
        glVertex2d(400.0+200.0*cos(angle+PI),300.0-200.0*sin(angle+PI));

        glTexCoord2d(0.0,1.0);
        glVertex2d(400.0+200.0*cos(angle-PI/2.0),300.0-200.0*sin(angle-PI/2.0));

        glEnd();

		// change the angle a bit to create spinning animation
        angle+=0.01;

        FsSwapBuffers();
        FsSleep(25);
    }

    return 0;
}


