#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


double gaussrand(int mu, double sigma)
{
	static double V1, V2, S;
	static int phase = 0;
	double X;

	if(phase == 0) 
	{
		do 
		{
			double U1 = (double)rand()/ RAND_MAX;
			double U2 = (double)rand()/ RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
			} while(S >= 1 || S == 0);

		X = V1 * sqrt(-2 * log(S) / S);
	} 
	else
		X = V2 * sqrt(-2 * log(S) / S);

	phase = 1 - phase;
	
	return (X*sigma + mu);
}

void getrands(double* arr){
	clock_t begin = clock();
	float s = 1.001;
	int m = 0;
	//double *arr;
	//arr = (double*) calloc(sizeof(double), 500000);

	for (int i = 0; i < 500000; ++i)
	{
		*(arr + i) = gaussrand(m, s);
	}
	clock_t end = clock();
	// for (int i = 0; i <500000; ++i)
	// {
	// 	if (i%10 == 0){ printf("\n");}
	// 	printf(",   %.5f",arr[i]);
	// }
	////free(arr);
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\ntime_spent = %f\n",time_spent);
	return ;
}
int main(){
	return 0;
}