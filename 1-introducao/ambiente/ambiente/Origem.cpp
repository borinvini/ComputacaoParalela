#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

	int i, P, T, ID;

	P = omp_get_num_procs();
	T = omp_get_num_threads();
	ID = omp_get_thread_num();
	printf("Thread id : %d #Procs: %d #Threads: %d\n\n\n\n\n", ID, P, T);

#pragma omp parallel
	{
		P = omp_get_num_procs();
		T = omp_get_num_threads();
		ID = omp_get_thread_num();
		printf("Thread id : %d #Procs: %d #Threads: %d\n", ID, P, T);
	}

	printf("\n\n\n\n");
#pragma omp parallel num_threads(8)
	{
		P = omp_get_num_procs();
		T = omp_get_num_threads();
		ID = omp_get_thread_num();
		printf("Thread id : %d #Procs: %d #Threads: %d\n", ID, P, T);
	}

	system("pause");
	return 0;
}