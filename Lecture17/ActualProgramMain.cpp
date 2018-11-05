#include "ActualProgram.h"

int main()
{
	FsOpenWindow(16, 16, 800, 600, 1);

	ActualProgram prog;

	ProgramFramework::KeyCallBack k;

	k.fsKey = FSKEY_SPACE;
	k.callback = std::bind(&ActualProgram::ChangeBackgroundColor, &prog);
	prog.AddKeyReaction(k);

	k.fsKey = FSKEY_ESC;
	k.callback = std::bind(&ActualProgram::Quit, &prog);
	prog.AddKeyReaction(k);

	while (!prog.quit) {
		FsPollDevice();
		prog.ProcessKey(FsInkey());
		prog.Draw();
		FsSleep(25);
	}
	return 0;
};
