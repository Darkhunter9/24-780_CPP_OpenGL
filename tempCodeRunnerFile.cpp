/*
24-780-B Engineering Computation Problem Set 1 - Stopwatch
Name: Zihao Ding
Andrew ID: zihaod
Date: 08/29/2018
Description: This program realizes the function of a timer, with a precision of +/- 1s.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(void)
{
    int start,stop;
    printf("24-780-B Engineering Computation Problem Set 1 - Stopwatch\n");
    printf("Press the ENTER key to start timer >");
    
    while (true)
    {
        if ('\n' == getchar()) 
        {
            start = time(NULL);
            printf("Press the ENTER key to stop timer >");
            while(true)
            {
                if ('\n' == getchar())
                {
                    stop = time(NULL);
                    break;
                }
            }
            break;
        }
        
    }

    printf("Time elapsed: %d seconds.", (stop-start));
    return 0;
}