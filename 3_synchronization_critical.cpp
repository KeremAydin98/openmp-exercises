#include <omp.h>
#include <cstdio>


#define NUM_THREADS 3
int main()
{
	int sum = 0;
	
	
	#pragma omp parallel for shared(sum)
	for(int i=0; i<10; i++)
	{
	  #pragma omp critical
	  {
	    sum += i;
	  }
	
	}
	
	printf("Parallel result is %d\n", sum);
	
	
	int seq_sum = 0;


	// This will cause a race condition
	#pragma omp parallel for shared(seq_sum)
	for(int i=0; i<10; i++)
	{
	    seq_sum += i;
	
	}
	
	printf("Sequential result is %d\n", seq_sum);
	
	
	return 0;

}
