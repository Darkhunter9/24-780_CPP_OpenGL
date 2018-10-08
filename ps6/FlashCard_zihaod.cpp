#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "FlashCard_zihaod.h"



FlashCard::FlashCard()
{
}


FlashCard::FlashCard(int multiA, int multiB)
{
	A = multiA;
	B = multiB;
}

void FlashCard::present()
{
	std::cout << A << " x " << B << " = ";
}

int FlashCard::solution()
{
	return A * B;
}