// fallingBall no-struct

#include "fssimplewindow.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

struct ball {
	double x;
	double y;
	double vx;
	double by;
};

void drawCircle(int cx, int cy, int rad, bool fill)
{
	const double PI = 3.1415927;

	if (fill)
		glBegin(GL_POLYGON);
	else
		glBegin(GL_LINE_LOOP);

	int i;
	for (i = 0; i < 64; i++) {
		double angle = (double)i * PI / 32.0;
		double x = (double)cx + cos(angle)*(double)rad;
		double y = (double)cy + sin(angle)*(double)rad;
		glVertex2d(x, y);
	}

	glEnd();
}

void move(double &x, double &y, double &vx, double &vy, double m, double dt)
{
	double fx, fy, ax, ay;

	ax = 0.0;
	ay = -9.8;

	x += vx * dt;
	y += vy * dt;

	vx += ax * dt;
	vy += ay * dt;
}

void bounce(double &x, double &y, double &vx, double &vy, double limitX, double limitY)
{
	if (abs(x)-1 >= limitX)
		vx *= -1;

	if (abs(y)-1 >= limitY)
		vy *= -1;

}

int main(void)
{
	double m, x, y, vx, vy, dt;

	m = 1.0;

	x = 10.0;
	y = 10.0;

	vx = 10.0;
	vy = 2.0;

	dt = 0.02;

	FsOpenWindow(16, 16, 800, 600, 1);

	while (true)
	{
		move(x, y, vx, vy, m, dt);
		bounce(x, y, vx, vy, 40, 30);

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		glColor3ub(0, 1, 0);
		drawCircle(400 + (x*10.0), 300 - y * 10.0, 10, 1);
		FsSwapBuffers();

		FsSleep(10);
	}
}