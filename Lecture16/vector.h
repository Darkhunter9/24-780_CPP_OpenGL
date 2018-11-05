#pragma once

template <class T, int N> class VecN {
protected:
	T v[N];
public:
	const T & getComponent(int i) const { return v[i]; }
	void setComponent(int i, const T &newValue);
};

class Vec3 : public VecN <double, 3>
{
public:
	inline const double x(void) const;
	inline const double y(void) const;
	inline const double z(void) const;
	void set(const double x, const double y, const double z);
};
