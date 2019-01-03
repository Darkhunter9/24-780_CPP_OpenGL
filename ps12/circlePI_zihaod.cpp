/*
24-780-B Engineering Computation Problem Set 12 - Multi-threaded PI
Name: Zihao Ding
Andrew ID: zihaod
Date: 11/16/2018
Description:
Using multi-threading to calculate PI
Each run is a CalculateResult object, stored in CalculateList
Each object has parameters of run#, resolution, # of threads, 
time, error, final results of this run,
and an array of UnitCircleCalcParam objects for each thread
*/
#include <stdio.h>
#include <time.h>
#include <thread>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

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

//each run is a CalculateResult object, stored in CalculateList
//each object has parameters of run#, resolution, # of threads,
//time, error, final results of this run,
//and an array of UnitCircleCalcParam objects for each thread
class CalculateResult 
{
public:
	int run;
	int resulotion;
	int threads;
	time_t time;
	double error;
	double value;
	UnitCircleCalcParam *calc;
};


int main(void)
{
	// threads and resolution can be changed easily in array
	vector<CalculateResult> CalculateList;
	int resolutionlist[] = {100,1000,10000,100000};
	int threadlist[] = {2, 4, 6, 8};

	for(int j = 0; j < sizeof(threadlist)/sizeof(threadlist[0]); j++)
	{
		for(int i = 0; i < sizeof(resolutionlist)/sizeof(resolutionlist[0]); i++)
		{
			CalculateResult temp;
			temp.threads = threadlist[j];
			temp.resulotion = resolutionlist[i];
			temp.run = CalculateList.size() + 1;
			temp.value = 0.0;

			temp.calc = new UnitCircleCalcParam[threadlist[j]];
			for(int k = 0; k < threadlist[j]; k++)
			{
				temp.calc[k].d = 1.0/(double)resolutionlist[i];
				temp.calc[k].x0 = 0.0;
				temp.calc[k].x1 = 1.0;
				temp.calc[k].y0 = 1.0/threadlist[j]*k;
				temp.calc[k].y1 = 1.0/threadlist[j]*(k+1);
			}
			
			CalculateList.push_back(temp);
		}
		
	}

	vector<CalculateResult>::iterator it = CalculateList.begin();
	for(; it != CalculateList.end(); it++)
	{
		time_t t0=time(NULL);

		//initiate all the threads and push into a vector
		vector<thread> currentthreads;
		currentthreads.resize(it->threads);
		for(int i = 0; i < it->threads; i++)
		{
			thread t(CalculateUnitCircleArea, &it->calc[i]);
			currentthreads[i].swap(t);
		}
		
		//join all threads and calculate
		for(int i = 0; i < it->threads; i++)
		{
			currentthreads[i].join();
		}
		
		t0=time(NULL)-t0;

		//final result calculation
		for(int i = 0; i < it->threads; i++)
		{
			it->value += it->calc[i].area;
		}

		it->value = 4.0*it->value;
		it->error = (it->value - PI) / PI;
		it->time = t0;
	}
	
	//output
	cout << "==========================  Overall results  ==============================" << endl;
	cout << "Run\tResolution\tThreads\tTime\tError\t\tValue" << endl;

	for(int i = 0; i < CalculateList.size(); i++)
	{
		cout << CalculateList[i].run << "\t"<< 
		CalculateList[i].resulotion << "\t\t"<< 
		CalculateList[i].threads << "\t" << 
		CalculateList[i].time << "\t" <<
		CalculateList[i].error << "\t";
		cout <<  setprecision(10) << CalculateList[i].value << endl;
	}
	

	system("pause");
	return 0;
}