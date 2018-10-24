#pragma once

using namespace std;

class CharBitmap
{
	public:
		CharBitmap();
		~CharBitmap();

		void cleanUp(); // used to reset and free up all space used by object
		void create(int w, int h); // initializes object with given dimensions
		void setPixel(int x, int y, unsigned char p); // sets the pixel value
		char getPixel(int x, int y) const; // returns the value/color of the pixel
		void draw() const; // draw the bitmap, magnified (use GL_QUADS) and colors
		// defined in pixels array.
		void load(const string fName); // load a bitmap from a file
		void save(const string fName) const; // save a bitmap to a file
		int width, height;
		

	private:
		
		char *pixels;
};