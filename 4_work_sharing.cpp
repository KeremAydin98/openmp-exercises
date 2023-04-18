#include <omp.h>
#include <cstdio>
#include <chrono>
#include <ostream>
#include <iostream>

int MAX = 10000000;

int main()
{

  double start_time = omp_get_wtime();

  double res[MAX],  kes[MAX], result[MAX];
  int i;

#pragma omp parallel for
  for(i=0;i<MAX;i++){
    res[i] = 10;
  }

#pragma omp parallel for
  for(i=0;i<MAX;i++){
    kes[i] = 10;
  }

	
#pragma omp parallel for
  for(i=0;i<MAX;i++){
    result[i] = res[i] + kes[i];
  }


	
  double end_time = omp_get_wtime();

  printf("Elapsed time: %f", end_time - start_time);


  return 0;
}