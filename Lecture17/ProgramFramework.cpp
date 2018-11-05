#include "ProgramFramework.h"

void ProgramFramework::AddKeyReaction(KeyCallBack k)
{
	keyReaction.push_back(k);
}
void ProgramFramework::ProcessKey(int fsKey)
{
	for (auto &k : keyReaction)
	{
		if (k.fsKey == fsKey)
		{
			k.callback();
		}
	}
}
