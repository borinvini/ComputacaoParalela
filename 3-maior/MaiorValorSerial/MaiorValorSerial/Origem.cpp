#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define TAMANHOVETOR 100000

int main()
{
	unsigned long vet[TAMANHOVETOR] = { 0 };
	unsigned long maior = 0;
	//srand(time(NULL));
	srand(1000);

	for (unsigned long int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = (rand() % 30000)*(rand() % 6);
	
	double start_time = omp_get_wtime(); //calcula tempo

	for (unsigned long int i = 0; i < TAMANHOVETOR; i++)
	{
		if (vet[i] > maior)
		{
			maior = vet[i];
		}
	}
	
	printf("Maior valor encontrado: %lu\n", maior);
	double end_time = omp_get_wtime(); //calcula tempo
	printf("%f s\n", (end_time - start_time));

	printf("\n");
	system("pause");
	return 0;
}