#include <iostream>
#include "vector.h"

template <class T, int N> T dotProduct(const VecN <T, N> &v1, 
				const VecN <T, N> &v2)
{
	T sum = 0;
	for (int i = 0; i < N; i++) 
		sum += v1.getComponent(i) * v2.getComponent(i);
	
	return sum;
}

//int main(void)
//{
//	VecN <double, 3> vec1, vec2;
//	vec1.setComponent(0, 1.0);
//	vec1.setComponent(1, 2.0);
//	vec1.setComponent(2, 3.0);
//
//	vec2.setComponent(0, 4.0);
//	vec2.setComponent(1, 5.0);
//	vec2.setComponent(2, 6.0);
//
//
//	printf("V1 %lf %lf %lf\n", vec1.getComponent(0), vec1.getComponent(1), vec1.getComponent(2));
//	printf("Dot Product %lf\n", dotProduct<double, 3>(vec1, vec2));
//
//	return 0;
//}

int main(void)
{
	Vec3 vec1, vec2;
	vec1.set(1.0, 2.0, 3.0);
	vec2.set(4.0, 5.0, 6.0);

	printf("Dot Product %lf\n", dotProduct(vec1, vec2));

	return 0;
}
