/*
24-780-B Engineering Computation Problem Set 2 - Multiplication flash cards
Name: Zihao Ding
Andrew ID: zihaod
Date: 09/06/2018
Description: 
1. Ask the user if they want to include 11 and 12 with a simple Y/N prompt. This will allow your program to adapt to modern realities.
2. Ask the user how many flash cards to work on. If they answered Y in step 1, the number needs to be between 1 and 144. If they answered N in step 1, the number needs to be between 1 and 100. If the user requests less than 1 or greater than the maximum valid flash cards, show a message (e.g. “The number of cards must be between 1 and ???.”) and prompt the user to re-enter a different number.
3. Show questions one by one on the console window and prompt the user to type the answer. If the user types a wrong answer, tell the user that the answer is wrong, show the correct answer, and then move on to the next card (i.e., no re-do). If the answer is correct, just move on to the next card.
4. When all the flash cards are answered, display a feedback comment that includes
    The number of problems presented,
    Time required to complete the problems in the number of seconds
    The number of correct answers
    The percent that the user answered correctly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

void shuffleArray(int array[], int swaptime)
{
    srand(unsigned(time(NULL)));
    int no1;
    for(int i = 0; i < swaptime; i++)
    {  
        no1 = rand() % swaptime;
        swap(array[i], array[no1]);
    }
}

void swapArray(int &num1, int &num2)
{
    int c;
    c = num1;
    num1 = num2;
    num2 = c;
}

int main(void)
{
    // whether to include 11 and 12
    string include1112;
    int maximum, card_number,dividenum;
    int start, stop;
    cout << "Whether to include 11 and 12 (Y/N):";
    cin >> include1112;
    
    // determine card number
    while(true)
    {
        cout << "How many flash cards to work on?";
        if ("Y" == include1112) 
        {
            cout << "(between 1 and 144):";
            maximum = 144;
            dividenum = 12;
        }
        
        else
        {
            cout << "(between 1 and 100):";
            maximum = 100;
            dividenum = 10;
        }

        cin >> card_number;
        
        if ((card_number >= 1) && (card_number <= maximum)) 
        {
            break;
        }
        else
        {
            cout << "The number of cards must be between 1 and " << maximum << endl;
        }
    }

    //shuffle the cards
    int array[144];
    for(int i = 0; i < maximum; i++)
    {
        array[i] = i;
    }
    shuffleArray(array,maximum);
    
    //ask and answer
    int correct = 0;
    int answer;
    start = time(NULL);

    for(int i = 0; i < card_number; i++)
    {
       int first_number = array[i] / dividenum + 1;
       int second_number = array[i] % dividenum + 1;
       cout << first_number << "*" << second_number << ":";
       cin >> answer;
       if (first_number*second_number == answer) 
       {
           correct++;
       }
       else
       {
           cout << "The answer is wrong." << endl;
           cout << "The right answer is:" << first_number * second_number << endl;
       }
       
    }

    stop = time(NULL);

    //result output
    double temp1 = correct, temp2 = card_number;
    double rate = temp1 / temp2 * 100;
    cout << "You answered " << card_number << " problems in " << stop-start << " seconds." << endl;
    cout << "You answered " << correct << " problems correctly " << "(" << setprecision(2)<<fixed<<rate << "%)." << endl;
    
    system("pause");
    return 0;
}