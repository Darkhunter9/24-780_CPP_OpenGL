#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

class FlashCard
{
	public:
		FlashCard();
		FlashCard(int multiA, int multiB);
		void present();
		int solution();
	private:
		int A;
		int B;
};
