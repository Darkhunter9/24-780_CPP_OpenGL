#include "matrix_zihaod.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

template <class T, int nr, int nc>
MatrixTemplate<T, nr, nc>::MatrixTemplate()
{
	NR = nr;
	NC = nc;
	m = new T[NR*NC];
}

template <class T, int nr, int nc>
MatrixTemplate<T, nr, nc>::MatrixTemplate(const MatrixTemplate<T, nr, nc> &old)
{
	this->NR = old.NR;
	this->NC = old.NC;
	this->m = new T[NR*NC];
	for (int i = 0; i < NR*NC; i++)
	{
		this->m[i] = old.m[i];
	}
}

/*
template <class T, int nr, int nc>
MatrixTemplate<T, nr, nc> & MatrixTemplate<T, nr, nc>::operater(const MatrixTemplate<T, nr, nc> &old)
{
	this->NR = old.NR;
	this->NC = old.NC;
	this->m = new T[NR*NC];
	for (int i = 0; i < NR*NC; i++)
	{
		this->m[i] = old.m[i];
	}
	return *this;
}
*/

template <class T, int nr, int nc>
MatrixTemplate<T, nr, nc>::~MatrixTemplate()
{
}

template <class T, int nr, int nc>
void MatrixTemplate<T, nr, nc>::set(int r, int c, const T &incoming) // sets value at given location
{
	m[(r-1)*NC+(c-1)] = incoming;
}

template <class T, int nr, int nc>
const T & MatrixTemplate<T, nr, nc>::value(int r, int c) const // gets value at given location
{
	return m[(r - 1)*NC + (c - 1)];
}

template <class T, int nr, int nc>
void MatrixTemplate<T, nr, nc>::print() const // prints the whole array to terminal
{
	for (int i = 0; i < NR; i++)
	{
		for (int j = 0; j < NC; j++)
		{
			std::cout << m[i*NC + j] << " ";
		}
		
		std::cout << std::endl;
	}
}

Matrix4x4::Matrix4x4()
{
}

Matrix4x4::~Matrix4x4()
{
}

void Matrix4x4::transpose()
{
	double *m1 = new double[NC*NR];
	for (int i = 0; i < NR; i++)
	{
		for (int j = 0; j < NC; j++)
		{
			m1[i*NC + j]= m[i*NC + j];
		}
	}

	for (int i = 0; i < NR; i++)
	{
		for (int j = 0; j < NC; j++)
		{
			m[i*NC + j] = m1[j*NC + i];
		}
	}
}

void Matrix4x4::invert()
{

}

template class MatrixTemplate<double, 4, 4>;