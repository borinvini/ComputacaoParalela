#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vet[]);

#define TAMANHOVETOR 100000

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

	BubbleSort(vet);

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

void BubbleSort(int vet[])
{
	int aux;
	for (int n = 1; n <= TAMANHOVETOR; n++) //Laço para o tamanho do vetor
	{
		for (int i = 0; i < (TAMANHOVETOR - 1); i++) //Laço da 1ª até a penultima posição
		{
			if (vet[i] > vet[i + 1])
			{
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;
			}

		}

	}

}