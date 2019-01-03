#pragma once

template <class T, int nr, int nc> 
class MatrixTemplate
{
	public:
		MatrixTemplate();
		//MatrixTemplate(T,int nr, int nc);
		~MatrixTemplate();
		MatrixTemplate(const MatrixTemplate<T, nr, nc> &old);

		void set(int r, int c, const T &incoming); // sets value at given location
		const T &value(int r, int c) const; // gets value at given location
		void print() const; // prints the whole array to terminal
		//MatrixTemplate<T, nr, nc> & operater(const MatrixTemplate<T, nr, nc> &old);

		
	protected:
		T *m;
		int NR;
		int NC;

	private:
		
		
};

class Matrix4x4:public MatrixTemplate <double,4,4>
{
	public:
		Matrix4x4();
		~Matrix4x4();
		void transpose(); // transposes the matrix
		void invert();

	private:

};





