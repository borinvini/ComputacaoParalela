#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

static long num_steps = 100000000;
double step;

int main()
{
	int i;
	double x, pi, sum = 0.0;

	step = 1.0 / (double)num_steps;
	double start_time = omp_get_wtime(); //calcula tempo

	for (i = 0; i < num_steps; i++)
	{
		x = (i + 0.5)*step;
		sum = sum + 4.0 / (1.0 + x*x);
	}
	pi = sum * step;

	double end_time = omp_get_wtime(); //calcula tempo

	printf("%f\n", pi);
	printf("%lf s\n", end_time - start_time);
	system("pause");
	return 0;
}