#include <stdio.h>
#include <time.h>

// Calculates area of a circle with radius=1.0

int main(void)
{
	const time_t t0 = time(NULL);

	const double d = 0.00004;
	const double dA = d * d;
	double area = 0.0;
	double rr;
	for (double y = -1.0; y < 1.0; y += d) {
		for (double x = -1.0; x < 1.0; x += d)
		{
			rr = x * x + y * y;
			if (rr < 1.0)
				area += dA;
		}
	}
	printf("Area of the circle is %lf\n", area);
	printf("Elapsed Time=%d\n", (int)(time(NULL) - t0));

	return 0;
}
