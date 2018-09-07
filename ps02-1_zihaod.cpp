/*
24-780-B Engineering Computation Problem Set 2 - Fast number typing
Name: Zihao Ding
Andrew ID: zihaod
Date: 09/06/2018
Description: 
1. Print a title message “24-780-B Eng Computation Problem Set 2-1\nFast Number Typing Game”
2. Prompt user to press ENTER when ready to begin
3. Generate a random integer 0-999.
4. Prompt the user to type in the number by printing “Type ???:”
5. Let the user enter an integer number.
6. If the user enters an incorrect number, print “Incorrect! Try again!” and go back to (4). Do not generate a new random number until the user enters the correct number.
7. Repeat (3) to (6) for ten random numbers in total.
8. Print the number of seconds that the user needed for typing 10 numbers correctly as “Elapsed ??? seconds.”
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(void)
{
    cout << "24-780-B Eng Computation Problem Set 2-1\nFast Number Typing Game" << endl;
    cout << "Press the ENTER key to start >";
    
    while('\n' != getchar());

    int start = time(NULL);

    srand(unsigned(time(NULL)));
    int answer,typing;
    for(int i = 0; i < 10; i++)
    {
        answer=rand()%1000;

        while(true){
            cout << "Type " << answer << ":";
            cin >> typing;
            if(answer == typing){
                break;
            }
            else{
                cout << "Incorrect! Try again!" << endl;
            }
        }
    }

    int stop = time(NULL);
    cout << "Elapsed " << stop-start << " seconds" << endl;
    system("pause");
    return 0;
}
