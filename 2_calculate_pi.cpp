#include <omp.h>
#include <cstdio>

static long num_steps = 1000000000;

double step;

# define PAD 8
#define NUM_THREADS 4
int main()
{
	int i, nthreads; 
	double x, pi, sum[NUM_THREADS][PAD];
	step = 1.0/(double) num_steps;

	double start_time = omp_get_wtime();
	
	step = 1.0/(double) num_steps;

	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel
	{

	int i, id, nthrds;
		double x;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (id==0) nthreads=nthrds;

	for (i=0;i<num_steps;i=i+nthrds)
	{
		x = (i+0.5) * step;
		sum[id][0] += 4.0/(1.0 + x*x);
	}

	}	
	
	for(i=0, pi=0.0;i<nthreads;i++)
	{	
	pi += step * sum[i][0];
	}

	

	double time = omp_get_wtime() - start_time;

	printf("Pi is %f\n", pi);
	printf("the time of difference is %f\n", time);

	
	
	return 0;

}