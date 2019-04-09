#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define MAX 100000

int main()
{
	double media = 0.0, A[MAX];
	srand(time(NULL));
	double start_time = omp_get_wtime(); //calcula tempo

	for (int i = 0; i < MAX; i++)
		A[i] = rand() % 100;

#pragma omp parallel for reduction (+:media)
	for (int i = 0; i < MAX; i++)
	{
		media += A[i];
	}
	media = media / MAX;

	double end_time = omp_get_wtime(); //calcula tempo
	printf("%f s\n", (end_time - start_time));

		system("pause");
	return 0;
}