#include <omp.h>
#include <cstdio>

static long num_steps = 1000000000;

double step;

#define NUM_THREADS 2
int main()
{
	int i, nthreads; 
	double pi;
	step = 1.0/(double) num_steps;

	double start_time = omp_get_wtime();

	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel
	{

	double local_sum = 0.0;
	double x;

	// set the thread number
	int id = omp_get_thread_num();
	// number of threads
	int nthrds = omp_get_num_threads();

	if (id==0) nthreads=nthrds;

	for (int i=0;i<num_steps;i=i+nthrds)
	{
		x = (i+0.5) * step;
		local_sum += 4.0/(1.0 + x*x);
	}
	

	#pragma omp critical
	pi += step * local_sum;
	
	}
	

	double time = omp_get_wtime() - start_time;

	printf("Pi is %f\n", pi);
	printf("the time of difference is %f\n", time);

	
	
	return 0;

}