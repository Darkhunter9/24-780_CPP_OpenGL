#include <stdio.h>
#include <time.h>
#include <thread>
#include <mutex>

// Calculates the area of a circle with radius=1.0

class UnitCircleCalcParam
{
public:
	std::mutex *mutexPtr;
	double *areaPtr;
	double d;
	double x0, x1, y0, y1;
};

void CalculateUnitCircleArea(UnitCircleCalcParam *paramPtr)
{
	auto &param = *paramPtr;

	const double d = param.d;
	const double dA = d * d;
	for (double y = param.y0; y < param.y1; y += d)
	{
		for (double x = param.x0; x < param.x1; x += d)
		{
			const double rr = x * x + y * y;
			if (rr < 1.0)
			{
				param.mutexPtr->lock();
				*(param.areaPtr) += dA;
				param.mutexPtr->unlock();
			}
		}
	}
}

int main(void)
{
	const time_t t0 = time(NULL);
	const double d = 0.00004;

	std::mutex mutex;
	double areaTotal = 0.0;
	UnitCircleCalcParam calc[2];

	calc[0].areaPtr = &areaTotal;
	calc[0].mutexPtr = &mutex;
	calc[0].d = d;
	calc[0].x0 = -1.0;
	calc[0].x1 = 1.0;
	calc[0].y0 = 0.0;
	calc[0].y1 = 1.0;

	calc[1].areaPtr = &areaTotal;
	calc[1].mutexPtr = &mutex;
	calc[1].d = d;
	calc[1].x0 = -1.0;
	calc[1].x1 = 1.0;
	calc[1].y0 = -1.0;
	calc[1].y1 = 0.0;

	std::thread th0(CalculateUnitCircleArea, &calc[0]);
	std::thread th1(CalculateUnitCircleArea, &calc[1]);
	th0.join();
	th1.join();

	printf("Area of the circle is %lf\n", areaTotal);
	printf("Elapsed Time=%d\n", (int)(time(NULL) - t0));

	return 0;
}