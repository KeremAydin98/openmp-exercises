#include <iostream>
#include <omp.h>

int main()
{
	int x = 5;
	int y = 20;
	
	#pragma omp parallel private(x) firstprivate(y)
	{
		x = 10; // x is undefined on entry, but now set to 10
		int z = x + y; // y was pre-initialized to a value of 20
		
		y = 30; // (first)private variables may be modified
	
	
	}

	
	return 0;


} // End of a parallel region
