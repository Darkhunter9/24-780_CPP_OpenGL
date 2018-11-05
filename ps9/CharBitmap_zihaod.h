#pragma once

using namespace std;

template <class T> 
class BitmapTemplate 
{
	private:
		
		
	protected:
		
	public:
		BitmapTemplate(); // default constructor of class (empty bitmap)
		BitmapTemplate(const BitmapTemplate <T> &incoming);// copy constructor of class
		~BitmapTemplate(); // destructor of class
		void cleanUp(); // used to reset and free up all space used by object
		void create(int w, int h); // initializes object with given dimensions
		void setPixel(int x, int y, const T &p); // sets the pixel value
		T getPixel(int x, int y) const; // returns the value/color of the pixel
		int getWidth() const { return width; } // return the width of the bitmap
		int getHeight() const { return height;} // return the height of the bitmap
		int width, height; // the size of the bitmap
		T *pixels; // the values of each of the pixels (stored in a 1D array)

		
		
		
};

class CharBitmap: public BitmapTemplate <char>
{
	public:
		CharBitmap();
		~CharBitmap();
		//char *pixels;

		/*
		void cleanUp(); // used to reset and free up all space used by object
		void create(int w, int h); // initializes object with given dimensions
		
		char getPixel(int x, int y) const; // returns the value/color of the pixel
		*/

		void draw() const; // draw the bitmap, magnified (use GL_QUADS) and colors
		void setPixel(int x, int y, unsigned char p); // sets the pixel value
		// defined in pixels array.
		void load(const string fName); // load a bitmap from a file
		void save(const string fName) const; // save a bitmap to a file
		//int width, height;
		

	protected:
		
		
};