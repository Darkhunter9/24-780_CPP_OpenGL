#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "BowlingScoreCalc_zihaod.h"

using namespace std;

BowlingScoreCalc::BowlingScoreCalc()
{
}

BowlingScoreCalc::~BowlingScoreCalc()
{
}

void BowlingScoreCalc::readScores(const std::string &input)
// parses input to assign an integer score to each roll
// prints (cout) "Too short" if input has insufficient data
// prints (cout) "Bad input" if input has invalid data
// on error, all values should be set to zero.
{
	memset(pinsKnockedDown, 0, sizeof(pinsKnockedDown));
	BadInput = false;
	if (input.size() < 20)
	{
		cout << "Too short" << endl;
		memset(pinsKnockedDown, 0, sizeof(pinsKnockedDown));
	}
	else
	{
		for (int i = 0; i < input.size(); i++)
		{
			switch (input[i])
			{
			case '0':
				pinsKnockedDown[i] = 0;
				break;
			case '1':
				pinsKnockedDown[i] = 1;
				break;
			case '2':
				pinsKnockedDown[i] = 2;
				break;
			case '3':
				pinsKnockedDown[i] = 3;
				break;
			case '4':
				pinsKnockedDown[i] = 4;
				break;
			case '5':
				pinsKnockedDown[i] = 5;
				break;
			case '6':
				pinsKnockedDown[i] = 6;
				break;
			case '7':
				pinsKnockedDown[i] = 7;
				break;
			case '8':
				pinsKnockedDown[i] = 8;
				break;
			case '9':
				pinsKnockedDown[i] = 9;
				break;
			case 'x':
				pinsKnockedDown[i] = 10;
				break;
			case 'X':
				pinsKnockedDown[i] = 10;
				break;
			case ('/'):
			{
				if (i == 0)
				{
					BadInput = true;
				}
				else
				{
					pinsKnockedDown[i] = 10 - pinsKnockedDown[i - 1];
				}
				break;
			}
			case ' ':
				pinsKnockedDown[i] = 0;
				break;
			case '-':
				pinsKnockedDown[i] = 0;
				break;
			default:
				BadInput = true;
				break;
			}
		}
		if (BadInput)
		{
			cout << "Bad input" << endl;
			memset(pinsKnockedDown, 0, sizeof(pinsKnockedDown));
		}
	}
}

void BowlingScoreCalc::reset()
// sets all pin counts to zero
{
	memset(pinsKnockedDown, 0, sizeof(pinsKnockedDown));
}

int BowlingScoreCalc::scoreForFrame(int frameNo)
// returns the score for the single requested frame (which
// may include more than two rolls).
// returns -1 for invalid frameNo (<1 or > 10)
{
	if ((frameNo < 1) || (frameNo > 10))
	{
		return -1;
	}
	else
	{
		if (frameNo != 10)
		{
			if (pinsKnockedDown[2 * (frameNo - 1)] == 10)
			{
				if (pinsKnockedDown[2 * frameNo] == 10)
				{
					return 20 + pinsKnockedDown[2 * (frameNo + 1)];
				}
				else
				{
					return 10 + pinsKnockedDown[2 * frameNo] + pinsKnockedDown[2 * frameNo + 1];
				}
			}
			else
			{
				if (pinsKnockedDown[2 * (frameNo - 1)] + pinsKnockedDown[2 * (frameNo - 1)+1] == 10)
				{
					return 10 + pinsKnockedDown[2 * frameNo];
				}
				else
				{
					return pinsKnockedDown[2 * (frameNo - 1)] + pinsKnockedDown[2 * (frameNo - 1) + 1];
				}
			}
		}
		else
		{
			return pinsKnockedDown[20] + pinsKnockedDown[19] + pinsKnockedDown[18];
		}
	}
}

int BowlingScoreCalc::scoreUpToFrame(int frameNo)
// returns total score up to requested frame
// returns 0 for frameNo < 1, returns final score for frameNo >= 10
{
	int total = 0;
	for (int i = 1; i < frameNo+1; i++)
	{
		total += scoreForFrame(i);
	}
	return total;
}