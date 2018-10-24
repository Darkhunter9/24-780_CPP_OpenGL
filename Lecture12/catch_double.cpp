double getDouble(const string &prompt)
{	// this function will read a double value and ask for re-entry 
	// if the input is not readable.

	double theValue;
	bool inputIsGood = false;
	string inputLine;

	while (!inputIsGood) {
		try { // this is a try-catch block
			cout << prompt;
			getline(cin, inputLine);  // gets the whole input, even spaces
			theValue = stod(inputLine.c_str()); // tries to convert to double
			inputIsGood = true;
		}
		catch (exception& e)
		{
			cin.sync(); // clear all values from cin
			cout << "Must enter a decimal number. ";
		}
	}
	return theValue;
}

/*
I call it in main() using:
neutralLength = getDouble("Enter the neutral length (L) >> ");
*/