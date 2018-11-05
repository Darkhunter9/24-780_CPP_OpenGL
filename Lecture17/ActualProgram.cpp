#include "ActualProgram.h"

ActualProgram::ActualProgram()
{
	g = 1;
	r = 0;
	b = 0;
	quit = false;
}
void ActualProgram::Draw(void) const
{
	glClearColor(r, g, b, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	FsSwapBuffers();
}

void ActualProgram::ChangeBackgroundColor(void)
{
	auto x = b;
	b = r;
	r = g;
	g = x;
}
void ActualProgram::Quit(void)
{
	quit = true;
}

