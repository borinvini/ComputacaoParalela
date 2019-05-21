#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define LINHAS 62              
#define COLUNAS_A 15                 
#define COLUNAS_B 7             

int main()
{
	int	id, nthreads, i, j, k, chunk;
	double	a[LINHAS][COLUNAS_A],           
		b[COLUNAS_A][COLUNAS_B],      
		c[LINHAS][COLUNAS_B];          

	chunk = 10;                    

#pragma omp parallel shared(a,b,c,nthreads,chunk) private(id,i,j,k)
	{
		id = omp_get_thread_num();
		if (id == 0)
		{
			nthreads = omp_get_num_threads();
			printf("Iniciando com %d threads\n", nthreads);
			printf("Inicializando matrizes...\n");
		}
		/*** Initialize matrices ***/
#pragma omp for schedule (static, chunk) 
		for (i = 0; i<LINHAS; i++)
			for (j = 0; j<COLUNAS_A; j++)
				a[i][j] = i + j;
#pragma omp for schedule (static, chunk)
		for (i = 0; i<COLUNAS_A; i++)
			for (j = 0; j<COLUNAS_B; j++)
				b[i][j] = i*j;
#pragma omp for schedule (static, chunk)
		for (i = 0; i<LINHAS; i++)
			for (j = 0; j<COLUNAS_B; j++)
				c[i][j] = 0;

		printf("Thread %d iniciando a multiplicar...\n", id);
#pragma omp for schedule (static, chunk)
		for (i = 0; i<LINHAS; i++)
		{
			printf("Thread=%d fez a linha=%d\n", id, i);
			for (j = 0; j<COLUNAS_B; j++)
				for (k = 0; k<COLUNAS_A; k++)
					c[i][j] += a[i][k] * b[k][j];
		}
	}  
	printf("******************************************************\n");
	printf("Matriz resultante:\n");
	for (i = 0; i<LINHAS; i++)
	{
		for (j = 0; j<COLUNAS_B; j++)
			printf("%6.2f   ", c[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}