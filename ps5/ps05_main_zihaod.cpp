/*
ps05_zihaod
Zihao Ding
10/01/2018

Features:
(1) This program realizes drawing/deleting circles with different and independent colors and radii.
(2) The process of drawing is completed using mouse movement and is shown in real time.
(3) Selection of colors is done easily through mouse-clicking on a triangle with color gradation in the window.

Instructions:
(1) Compile and run the program
(2) The default color is blue. Whenever you left click on the triangle with color gradation, it will change the color selected accordingly and show RGB information on the top left corner (even the words change the color accordingly).
(3) When you left click and hold at other parts in the window, the process of drawing circle begins. The color of circle is the one indicated by RGB information. The location you first click is the center, and the radius continuously changes and shows in real time as you hold the click and move the mouse.
(4) After you release the left-click, the circle you just drew stays in the window. You can delete circles using ¡°BackSpace¡± button, which will erase circles in a reversed order.
(5) Push ¡°ESC¡± anytime to terminate the program.

*/


#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include "ps05_zihaod.h"

using namespace std;

int main(void)
{
    bool terminate = false;
    int key;
    int leftButton, middleButton, rightButton, locX, locY;
	int mouseEvent;
    string shape;
    Colorset colorset;
    colorset.R = 0;
    colorset.G = 0;
    colorset.B = 250;
    double circleX = 0;
    double circleY = 0;
    Circle *shape1 = NULL;
    Circle **currShape = &shape1;

    FsOpenWindow(16, 16, 800, 600, 1);

    while (! terminate)
    {
        FsPollDevice();
        key = FsInkey();

        mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY);

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        switch (key) 
        {
            case FSKEY_ESC:
                terminate = true;
                break;
            case FSKEY_BS:
                popCircle(*currShape);
                break;
        }

        
        switch (mouseEvent)
        {
            case FSMOUSEEVENT_LBUTTONDOWN:
                if (locX >= 720 && locX <= 800 && locY >= 0 && locY <= 80) 
                {
                    if (InTriangle(locX, locY)) 
                    {
                        colorset = GetColor(locX, locY);
                    }   
                }
                else
                {
                    if (! circleX && ! circleY) 
                    {
                       circleX = locX;
                       circleY = locY;
                    }
                }
                break;
            case FSMOUSEEVENT_LBUTTONUP:
                if (!(locX >= 720 && locX <= 800 && locY >= 0 && locY <= 80)) 
                {
                    pushCircle(circleX, circleY, locX, locY, colorset, shape1);
                    currShape = &shape1;
                }
                circleX = 0;
                circleY = 0;
                break;
        }

        PrintColor(colorset);

        if ((leftButton == 1) && !(locX >= 720 && locX <= 800 && locY >= 0 && locY <= 80)) 
        {
            DrawCircle(circleX, circleY, locX, locY, colorset);
        }

        DrawShape(shape1);

        DrawColorBar(colorset);

        FsSwapBuffers();
        FsSleep(10);

    }
    return 0;
}