#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 8 //PARALELA
#define PAD 8 //assumindo 64 bytes de cache line L1 

static long num_steps = 100000000;
double step;

int main()
{
	int i, nthreads;
	double pi, sum[NUM_THREADS][PAD]; //array para armazenar todas as somas

	step = 1.0 / (double)num_steps;
	int tam = sizeof(double);
	double start_time = omp_get_wtime(); //calcula tempo

	omp_set_num_threads(NUM_THREADS); //PARALELA
#pragma omp parallel
	{
		int i, id, nthrds;
		double x;
		id = omp_get_thread_num(); //pego o numero da thread
		nthrds = omp_get_num_threads(); //pego o total de threads para fazer o FOR depois
										//quando entramos na regi�o paralela, por algum motivo o "ambiente" pode escolher
										//nos dar menor threads do que definimos. Portanto esta checagem abaixo � para ver
										//quando threads realmente temos.
										//O numero real de threads depende do SO, arquitetura, etc.
		if (id == 0)
			nthreads = nthrds;

		for (i = id, sum[id][0] = 0.0; i < num_steps; i = i + nthrds) //distribui��o c�clica (distribui��o round robin)
		{ //id = 0, temos 0, 4, 8, 12... id = 1, temos 1, 5, 9, 13...
			x = (i + 0.5)*step;
			sum[id][0] = sum[id][0] + 4.0 / (1.0 + x*x);
		}
	}

	for (i = 0, pi = 0.0; i < nthreads; i++)
		pi = pi + sum[i][0] * step;

	double end_time = omp_get_wtime(); //calcula tempo

	printf("%f\n", pi);
	printf("%f s\n", (end_time - start_time));
	system("pause");
	return 0;
}