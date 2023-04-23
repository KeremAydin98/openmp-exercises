#include <iostream>
#include <cstdio>
#include <omp.h>

int main()
{
	#pragma omp parallel
	{
		do_many_things();
	#pragma omp master
	{
		exchange_boundaries();
	}
	#pragma omp barrier
		do_many_other_things();
	
	}


}
