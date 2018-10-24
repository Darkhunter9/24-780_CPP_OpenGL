#pragma once
#include <string>

using namespace std;

class Line2D
{
	public:
		Line2D();
		~Line2D();

		void draw();
		void makeFromString(const string info);
		void adjustZoom(const double locX, const double locY, const double newScaleFactor);
		void pan(const int locX, const int locY, const int prevLocX, const int prevLocY);

	private:

	protected:
		int X1,Y1,X2,Y2,R,G,B;
		double Scale = 1;

};