#include <stdio.h>
#include <time.h>
#include <thread>

// Calculates area of a circle with radius=1.0

class UnitCircleCalcParam
{
public:
	double area;
	double d;
	double x0, x1, y0, y1;
};

void CalculateUnitCircleArea(UnitCircleCalcParam *paramPtr)
{
	auto &param = *paramPtr;

	const double d = param.d;
	const double dA = d * d;
	param.area = 0.0;
	for (double y = param.y0; y < param.y1; y += d)
	{
		for (double x = param.x0; x < param.x1; x += d)
		{
			const double rr = x * x + y * y;
			if (rr < 1.0)
			{
				param.area += dA;
			}
		}
	}
}

int main(void)
{
	const time_t t0 = time(NULL);
	const double d = 0.00004;

	UnitCircleCalcParam calc[2];

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

	std::thread th0(CalculateUnitCircleArea, &calc[0]);
	std::thread th1(CalculateUnitCircleArea, &calc[1]);
	th0.join();
	th1.join();

	const double area = calc[0].area + calc[1].area;

	printf("Area of the circle is %lf\n", area);
	printf("Elapsed Time=%d\n", (int)(time(NULL) - t0));

	return 0;
}