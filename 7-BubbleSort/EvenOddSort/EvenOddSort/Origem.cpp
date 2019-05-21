#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void OddEvenSort(int vet[]);

#define TAMANHOVETOR 100

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	srand(time(NULL));


	//INSERÇÃO DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 10000;

	printf("VETOR NAO ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME NÃO ORDENADO
		printf("%d\n", vet[i]);

	clock_t t;
	t = clock();

	OddEvenSort(vet);

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds 

													  //IMPRESSÃO DE RESULTADOS
	printf("VETOR ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME ORDENADO
		printf("%d\n", vet[i]);

	printf("Took %f seconds to execute \n", time_taken);

	printf("\n");
	system("pause");
	return 0;
}

void OddEvenSort(int vet[])
{
	int flag = 1;
	int start = 0; //varial que alterna entre par e impar
	int temp;

	while(flag || start) {
		flag = 0;
		for(int i = start; i < TAMANHOVETOR - 1; i += 2) 
		{
			if (vet[i] > vet[i + 1]) 
			{
				temp = vet[i]; 
				vet[i] = vet[i + 1];
				vet[i + 1] = temp;
				flag = 1;
			}
		}
		if(start == 0) 
			start = 1;
		else 
			start = 0;
	}
}