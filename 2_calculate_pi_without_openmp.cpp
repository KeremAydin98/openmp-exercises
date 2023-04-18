#include <cstdio>
#include <omp.h>

static long num_steps = 1000000000;

double step;

int main()
{
	int i, nthreads; 
	double x, pi, sum = 0.0;
	step = 1.0/(double) num_steps;

	double start_time = omp_get_wtime();
	

	for(i=0;i<num_steps;i++){
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}

	pi = step * sum;

	double time = omp_get_wtime() - start_time;

	printf("Pi is %f\n", pi);
	printf("the time of difference is %f\n", time);

	
	
	return 0;

}