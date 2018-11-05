#pragma once
#include "ProgramFramework.h"

class ActualProgram : public ProgramFramework
{
public:
	float r, g, b;
	bool quit;

	ActualProgram();
	void Draw(void) const;
	void ChangeBackgroundColor(void);
	void Quit(void);
};
