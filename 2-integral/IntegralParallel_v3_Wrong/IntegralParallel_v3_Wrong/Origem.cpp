#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_THREADS 8 //PARALELA

static long num_steps = 100000000;
double step;

int main()
{
	int i, nthreads;
	double pi = 0.0; //array para armazenar todas as somas

	step = 1.0 / (double)num_steps;
	double start_time = omp_get_wtime(); //calcula tempo

	omp_set_num_threads(NUM_THREADS); //PARALELA
#pragma omp parallel
	{
		int i, id, nthrds;
		double x, sum;
		id = omp_get_thread_num(); //pego o numero da thread
		nthrds = omp_get_num_threads(); //pego o total de threads para fazer o FOR depois
										//quando entramos na regi�o paralela, por algum motivo o "ambiente" pode escolher
										//nos dar menor threads do que definimos. Portanto esta checagem abaixo � para ver
										//quando threads realmente temos.
										//O numero real de threads depende do SO, arquitetura, etc.
		if (id == 0)
			nthreads = nthrds;

		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		for (i = id, sum = 0.0; i < num_steps; i = i + nthrds) //distribui��o c�clica (distribui��o round robin)
		{ //id = 0, temos 0, 4, 8, 12... id = 1, temos 1, 5, 9, 13...
			x = (i + 0.5)*step;
#pragma omp critical //se��o critica dentro do loop praticamente serializa o c�digo
			pi = pi + 4.0 / (1.0 + x*x);
		}
	}
	pi = pi * step;

	double end_time = omp_get_wtime(); //calcula tempo

	printf("%f\n", pi);
	double time = end_time - start_time;
	printf("%f s\n", (end_time - start_time));
	system("pause");
	return 0;
}