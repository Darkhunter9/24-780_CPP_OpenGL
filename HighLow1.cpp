//test
/* test */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(void)
{
	int answer,guess,currentTime;

	currentTime=time(NULL);
	srand(currentTime);

	answer=rand();
	answer=answer%10;

	// cout << "Make a guess (0 to 9):";
    printf("Make a guess (0 to 9):");
    // cin >> guess
	scanf("%d",&guess);

	if(answer==guess)
	{
		printf("You've got the right answer!\n");
	}
	else
	{
		printf("Wrong. The answer is %d\n",answer);
	}
    
    system("pause");
	return 0;
}