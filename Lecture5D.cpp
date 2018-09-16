#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fssimplewindow.h"

void DrawRect(int x1,int y1,int x2,int y2,int fill)
{
    if(0!=fill)
    {
        glBegin(GL_QUADS);
    }
    else
    {
        glBegin(GL_LINE_LOOP);
    }

    glVertex2i(x1,y1);
    glVertex2i(x2,y1);
    glVertex2i(x2,y2);
    glVertex2i(x1,y2);

    glEnd();
}
void DrawRandomRect(void)
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
    DrawRect(x1,y1,x2,y2,0);
}

int main(void)
{
    FsOpenWindow(16,16,800,600,0);

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    srand(time(NULL));
    while(FSKEY_NULL==FsInkey())
    {
        DrawRandomRect();
        glFlush();
        FsPollDevice();
        FsSleep(10);
    }
    return 0;
}