#include <iostream>

class FunctionEvaluator
{
public:
	virtual double Evaluate(const double x) const;
};

class PolynomialFunction : public FunctionEvaluator
{
public:
	virtual double Evaluate(const double x) const;
	// note: "virtual" keyword can be ommitted in child class.
};

class XSquare : public PolynomialFunction
{
public:
	double k;
	XSquare();
	virtual double Evaluate(const double x) const;
	// note: "virtual" keyword can be ommitted in child class.
};

double FunctionEvaluator::Evaluate(const double x) const
{
	return 0.0;
}

double PolynomialFunction::Evaluate(const double x) const
{
	return 0.0;
}

XSquare::XSquare()
{
	k = 1.0;
}

double XSquare::Evaluate(const double x) const
{
	return k * x*x;
}



double IntegrateFunction(const double x0, const double x1,
	const double step, const FunctionEvaluator &func)
{
	double sum = 0.0;
	for (double x = x0; x <= x1; x += step)
		sum += func.Evaluate(x) * step;

	return sum;
}

int main(void)
{
	using namespace std;
	XSquare func;
    cout << "Integral of x*x from 0 to 1 is: "
		<< IntegrateFunction(0.0, 1.0, 0.0001, func) << endl;
    system("pause");
	return 0;
    
}