#ifndef BALLSHUFFLE_H
#define BALLSHUFFLE_H

#define END_OF_BOX '*'

int shuffle(char theBox[], int boxSize);
int shuffleBlind(char theBox[], int boxSize);


int moveAll(char theBox[], int boxSize, int direction);
void printBox(char theBox[]);
void swapArray(char theBox[], int indexA, int indexB);
bool initializeBox(char aBox[], int numberOfBalls);


#endif