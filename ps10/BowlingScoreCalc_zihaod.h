#pragma once

#include <string>
#include <stdlib.h>
#include <stdio.h>

class BowlingScoreCalc
{
public:
	BowlingScoreCalc();
	~BowlingScoreCalc();

	void readScores(const std::string &input);
	// parses input to assign an integer score to each roll
	// prints (cout) "Too short" if input has insufficient data
	// prints (cout) "Bad input" if input has invalid data
	// on error, all values should be set to zero.
	void reset();
	// sets all pin counts to zero
	int scoreForFrame(int frameNo);
	// returns the score for the single requested frame (which
	// may include more than two rolls).
	// returns -1 for invalid frameNo (<1 or > 10)
	int scoreUpToFrame(int frameNo);
	// returns total score up to requested frame
	// returns 0 for frameNo < 1, returns final score for frameNo >= 10


private:
	int pinsKnockedDown[21]; // pins dropped for each roll in game
	bool BadInput = false;
};
