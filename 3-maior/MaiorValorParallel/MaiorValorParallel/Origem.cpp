#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define TAMANHOVETOR 100000
#define NUM_THREADS 4

int main()
{
	int nthreads;
	unsigned long vet[TAMANHOVETOR] = { 0 };
	unsigned long maior = 0;
	//srand(time(NULL));
	srand(1000);

	for (unsigned long int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = (rand() % 30000)*(rand() % 6);

	double start_time = omp_get_wtime(); //calcula tempo

	omp_set_num_threads(NUM_THREADS); //PARALELA
#pragma omp parallel
	{
		unsigned long int i, id, nthrds, my_maior = 0;
		id = omp_get_thread_num(); //pego o numero da thread
		nthrds = omp_get_num_threads(); //pego o total de threads para fazer o FOR depois
		if (id == 0)
			nthreads = nthrds;

		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		for (i = id; i < TAMANHOVETOR; i = i + nthrds)
		{ 
			if (vet[i] > my_maior)
				my_maior = vet[i];
		}
#pragma omp critical
		{		
			if (my_maior > maior)
				maior = my_maior; 
		}
	}
	
	printf("Maior valor encontrado: %lu\n", maior);
	double end_time = omp_get_wtime(); //calcula tempo
	printf("%f s\n", (end_time - start_time));

	printf("\n");
	system("pause");
	return 0;
}