#include <stdio.h>
#include <time.h>
#include <thread>

// Calculates area of a circle with radius=1.0

class UnitCircleAreaCalculator
{
public:
	double area;
	double d;
	double x0, x1, y0, y1;

	static void ThreadEntry(UnitCircleAreaCalculator *thisPtr);
	void Calculate(void);
};

/* static */ void UnitCircleAreaCalculator::ThreadEntry(UnitCircleAreaCalculator *thisPtr)
{
	thisPtr->Calculate();
}

void UnitCircleAreaCalculator::Calculate(void)
{
	const double dA = d * d;
	area = 0.0;
	for (double y = y0; y < y1; y += d)
		for (double x = x0; x < x1; x += d)
			if (x * x + y * y < 1.0)
				area += dA;
}

int main(void)
{
	const time_t t0 = time(NULL);
	const double d = 0.00004;

	UnitCircleAreaCalculator calc[2];

	calc[0].d = d;
	calc[0].x0 = -1.0;
	calc[0].x1 = 1.0;
	calc[0].y0 = 0.0;
	calc[0].y1 = 1.0;

	calc[1].d = d;
	calc[1].x0 = -1.0;
	calc[1].x1 = 1.0;
	calc[1].y0 = -1.0;
	calc[1].y1 = 0.0;

	std::thread th0(UnitCircleAreaCalculator::ThreadEntry, &calc[0]);
	std::thread th1(UnitCircleAreaCalculator::ThreadEntry, &calc[1]);
	th0.join();
	th1.join();

	const double area = calc[0].area + calc[1].area;

	printf("Area of the circle is %1.20lf\n", area);
	printf("Elapsed Time=%d\n", (int)(time(NULL) - t0));

	return 0;
}
