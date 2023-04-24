#include <cstdio>
#include <omp.h>

int main()
{
  int sum = 0;
  
  
  #pragma omp parallel for lastprivate(sum)
  for(int i=0; i<100; i++)
  {
    sum += i;
  
  }
  
  printf("Total sum is %d\n", sum);
  
  return 0;

}
