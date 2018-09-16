#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fssimplewindow.h"

void DrawRandomLine(void)
{
    int x1,y1,x2,y2;
    int r,g,b;
    x1=rand()%800;
    y1=rand()%600;
    x2=rand()%800;
    y2=rand()%600;
    r=rand()%256;
    g=rand()%256;
    b=rand()%256;

    glColor3ub(r,g,b);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
	 glEnd();
}
int main(void)
{
    FsOpenWindow(16,16,800,600,0);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    srand(time(NULL));
    while(FSKEY_NULL==FsInkey())
    {
        DrawRandomLine();
        glFlush();
        FsPollDevice();
        FsSleep(10);
    }
    return 0;
}