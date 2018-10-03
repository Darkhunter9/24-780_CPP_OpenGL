#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fssimplewindow.h"

int main(void)
{
    FsOpenWindow(16,16,400,400,0);

    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0xff00);

    glShadeModel(GL_SMOOTH);
    glBegin(GL_LINE_LOOP);

    glColor3ub(255,0,0);
    glVertex2i(20,20);

    glColor3ub(0,255,0);
    glVertex2i(380,20);

    glColor3ub(0,0,255);
    glVertex2i(380,380);

    glColor3ub(255,255,0);
    glVertex2i(20,380);

    glEnd();

    glDisable(GL_LINE_STIPPLE);

    glFlush();

    while(FSKEY_NULL==FsInkey())
    {
        FsPollDevice();
        FsSleep(10);
    }

    return 0;
}