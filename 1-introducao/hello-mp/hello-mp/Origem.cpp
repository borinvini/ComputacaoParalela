#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

#pragma omp parallel num_threads(8)
	{
		int ID = omp_get_thread_num();
		printf("hello  %d\n", ID);
		printf("hello again %d\n", ID);
	}

	system("pause");
	return 0;
}