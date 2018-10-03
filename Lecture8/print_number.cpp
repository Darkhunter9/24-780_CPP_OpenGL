#include <string>

	string intAsText;
	intAsText = to_string(input[i]);
	YsGlDrawFontBitmap7x10(intAsText.c_str());

char number[5];   // for printing numbers
		// text (just for fun, not required)
		// set position
		glRasterPos2i((input[i] - 0.85) * blockSize, currY - blockSize / 4);  
		// get a char * string
		_itoa_s(input[i], number, 10);   // the "10" means convert to base-10 number
		// draw the text
		YsGlDrawFontBitmap7x10(number);