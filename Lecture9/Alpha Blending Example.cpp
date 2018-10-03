#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fssimplewindow.h"

void DrawScreen(int patchX,int patchY)
{
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    glShadeModel(GL_SMOOTH);

    glBegin(GL_QUADS);

    glColor3ub(255,0,0);
    glVertex2i(20,20);
    glColor3ub(0,255,0);
    glVertex2i(380,20);
    glColor3ub(0,0,255);
    glVertex2i(380,380);
    glColor3ub(255,255,0);
    glVertex2i(20,380);

    glEnd();


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glColor4ub(128,128,128,100);
    glBegin(GL_QUADS);
    glVertex2i(patchX   ,patchY);
    glVertex2i(patchX+40,patchY);
    glVertex2i(patchX+40,patchY+40);
    glVertex2i(patchX   ,patchY+40);
    glEnd();

    glDisable(GL_BLEND);

    FsSwapBuffers();
}

int main(void)
{
    int key,patchX=0,patchY=0;

    FsOpenWindow(16,16,400,400,1);

    while(FSKEY_ESC!=(key=FsInkey()))
    {
        FsPollDevice();

        switch(key)
        {
        case FSKEY_LEFT:
            patchX-=10;
            break;
        case FSKEY_RIGHT:
            patchX+=10;
            break;
        case FSKEY_UP:
            patchY-=10;
            break;
        case FSKEY_DOWN:
            patchY+=10;
            break;
        }

        DrawScreen(patchX,patchY);
        FsSleep(10);
    }

    return 0;
}