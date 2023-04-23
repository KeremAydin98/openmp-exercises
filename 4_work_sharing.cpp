#include <omp.h>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <vector>

int MAX = 100000;

int main()
{

  double start_time = omp_get_wtime();

  std::vector<double> res(MAX),  kes(MAX), result(MAX);

#pragma omp parallel for
  for(int i=0;i<MAX;i++){
    res[i] = 10;
    kes[i] = 10;
    result[i] = res[i] + kes[i];
  }


  double end_time = omp_get_wtime();

  printf("Elapsed time with openmp: %f\n", end_time - start_time);
  
  
  double start_time_2 = omp_get_wtime();

  std::vector<double> res_2(MAX),  kes_2(MAX), result_2(MAX);


  for(int i=0;i<MAX;i++){
    res_2[i] = 10;
    kes_2[i] = 10;
    result_2[i] = res_2[i] + kes_2[i];
  }


  double end_time_2 = omp_get_wtime();

  printf("Elapsed time without openmp: %f\n", end_time_2 - start_time_2);





  return 0;
}
