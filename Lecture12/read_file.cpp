#include <fstream>

void FlashCard::loadBlockLetters()
{	// Read data file to obtain fonts

	ifstream inFile;
	string temp;

	inFile.open("blockFontNumbers.txt");

	if (inFile.is_open()) {
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 6; j++) {
				// use getline instead of >> in order to get blanks spaces
				if (!inFile.eof())
					getline(inFile, blockFont[i][j]);
			}

			// read blank line between numbers
			if (!inFile.eof())
				getline(inFile, temp);

		}
	}
	inFile.close();
}