#pragma once
#include <string>
#include <vector>
#include "Line2D_zihaod.h"

using namespace std;

class Drawing2D
{
	public:
		Drawing2D();
		~Drawing2D();

		void draw();
		void readFile(const string fName);
		void clear();
		void adjustZoom(const double locX, const double locY, const double newScaleFactor);
		void pan(const int locX, const int locY, const int prevLocX, const int prevLocY);

	private:

	protected:
		vector<Line2D> Line;
		double Scale = 1;
};