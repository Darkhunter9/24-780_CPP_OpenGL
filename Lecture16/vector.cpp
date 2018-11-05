#include "vector.h"

//template <class T, int N>
//const T &VecN <T, N>::getComponent(int i) const
//{
//	return v[i];
//}

template <class T, int N>
void VecN <T, N>::setComponent(int i, const T &newValue)
{
	v[i] = newValue;
}


inline const double Vec3::x(void) const
{
	return getComponent(0);
}

inline const double Vec3::y(void) const
{
	return getComponent(1);
}

inline const double Vec3::z(void) const
{
	return getComponent(2);
}

void Vec3::set(const double x, const double y, const double z)
{
	setComponent(0, x);
	setComponent(1, y);
	setComponent(2, z);
}
