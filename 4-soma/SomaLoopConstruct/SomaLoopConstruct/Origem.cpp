#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define NUM_THREADS 8
#define TAMANHO 100000
#define CHUNK 100

int main()
{
	int a[TAMANHO], b[TAMANHO];
	srand(time(NULL));
	double start_time = omp_get_wtime(); //calcula tempo

//#pragma omp parallel for		
	for (int i = 0; i < TAMANHO; i++)
	{
		a[i] = rand() % 100;
		b[i] = rand() % 100;
	}

//#pragma omp parallel for
//#pragma omp parallel for schedule(static)	
//#pragma omp parallel for schedule(static, CHUNK)	
//#pragma omp parallel for schedule(dynamic)	
#pragma omp parallel for schedule(dynamic, CHUNK)	
		for (int i = 0; i < TAMANHO; i++)
		{
			a[i] = a[i] + b[i];
		}


	double end_time = omp_get_wtime(); //calcula tempo
	printf("%f s\n", (end_time - start_time));

	system("pause");
	return 0;

}