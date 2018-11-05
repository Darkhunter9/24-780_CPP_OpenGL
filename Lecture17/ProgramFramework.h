#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <vector>

#include "fssimplewindow.h"

class ProgramFramework
{
public:
	class KeyCallBack
	{
	public:
		int fsKey;
		std::function <void()> callback;
	};

	std::vector <KeyCallBack> keyReaction;

	void AddKeyReaction(KeyCallBack k);
	void ProcessKey(int fsKey);
};

