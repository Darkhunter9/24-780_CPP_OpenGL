/*
						 ! ! ! !
					  ." ! ! !  /
					."   ! !   /     Nestor Gomez
				  ."     !    /      Carnegie Mellon University
				."           /       Eng. Computation, 24-780-B
			  ."     o      /        Prob Set 10, Due Tues. Nov. 6, 2018
			."             /
		  ."              /          Use this tester program to check that
		."               /           your BowlingScoreCalc class is running
	  ."      . '.      /            smoothly. Feel free to edit and/or add
	."      '     '    /             to this tester to improve how well it
  ."                  /              helps you to develop your code.
."     0 |           /
	   |/
	  /|
	  / |

*/
#include <iostream>
#include "BowlingScoreCalc_zihaod.h"    // change andrewID as needed\

int main()
{
	using namespace std;

	cout << "Welcome to the 24-780-B Bowling Score Calculator" << endl;
	cout << string(50, '=') << endl;
	cout << "This program will test your code to assure it is working correctly" << endl;
	cout << "Some of the test will be hardcoded and other will require user input" << endl << endl;

	BowlingScoreCalc theScoreCalc;
	/* with error
	// harcoded test one 
	cout << endl;
	theScoreCalc.readScores("9/90X X 9/X X X 9/XX8");
	cout << "1) Score for frame 5 = " << theScoreCalc.scoreForFrame(5)
		<< "  << should be 30" << endl;
	cout << "1) Score after frame 5 = " << theScoreCalc.scoreUpToFrame(5)
		<< "  << should be 97" << endl;
	*/

	
		// harcoded test one 
	cout << endl;
	theScoreCalc.readScores("9/90X X 9/X X X 9/XX8");
	cout << "1) Score for frame 6 = " << theScoreCalc.scoreForFrame(6)
		<< "  << should be 30" << endl;
	cout << "1) Score after frame 6 = " << theScoreCalc.scoreUpToFrame(6)
		<< "  << should be 127" << endl;

	// harcoded test two
	cout << endl;
	theScoreCalc.readScores("919054x-9061x0 99/x72");
	cout << "2) Score for frame 7 = " << theScoreCalc.scoreForFrame(7)
		<< "  << should be 19" << endl;
	cout << "2) Score after frame 7 = " << theScoreCalc.scoreUpToFrame(7)
		<< "  << should be 91" << endl;

	// harcoded test three
	cout << endl;
	theScoreCalc.readScores("9154x-9061x0 99/x72");
	cout << "3) Should output 'Too short'" << endl;
	cout << "3) Score for frame 3 = " << theScoreCalc.scoreForFrame(3)
		<< "  << should be 0" << endl;
	cout << "3) Score after frame 3 = " << theScoreCalc.scoreUpToFrame(3)
		<< "  << should be 0" << endl;
	
	// harcoded test four
	cout << endl;
	theScoreCalc.readScores("919054x-9061x0 99/x7f");
	cout << "4) Should output 'Bad input'" << endl;
	cout << "4) Score for frame 9 = " << theScoreCalc.scoreForFrame(9)
		<< "  << should be 0" << endl;
	cout << "4) Score after frame 9 = " << theScoreCalc.scoreUpToFrame(9)
		<< "  << should be 0" << endl;

	// user input tests
	string testInput;
	for (int i = 0; i < 3; i++) {
		cout << endl;
		cout << "Input bowling score " << i << ": ";
		getline(cin, testInput);
		theScoreCalc.readScores(testInput);
		for (int j = 1; j <= 10; j++)
			cout << j << ") " << theScoreCalc.scoreUpToFrame(j) << " ";
	}
}
