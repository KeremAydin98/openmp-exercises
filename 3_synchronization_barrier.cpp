#include <iostream>
#include <cstdio>
#include <omp.h>


int bigcalc(int id, int A[], int B[]);


int main()
{
	int A[10];
	int B[10];


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
		printf(" The result is %d\n", B[i]);
	}
	
}

int bigcalc(int id, int A[], int B[])
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


