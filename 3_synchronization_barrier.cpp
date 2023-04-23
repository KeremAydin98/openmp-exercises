#include <iostream>
#include <cstdio>
#include <omp.h>


int bigcalc(int id, double A[], double B[]);


int main()
{
	double A[10];
	double B[10];	


	#pragma omp parallel
	{
		// every thread get their thread number
		int id = omp_get_thread_num();
		A[id] = id;
	
	// wait until every thread is done
	#pragma omp barrier
		
		B[id] = bigcalc(id, A, B);
	}
	
	for(int i; i<10; i++)
	{
		printf(" The result is %f\n", B[i]);
	}
	
}

int bigcalc(int id, double A[], double B[])
{
	
	if (id>0)
	{
		B[id] = A[id] * A[id -1];
	}
	else
	{
		B[id] = A[id];
	}

	return B[id];
}


