#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void matrixMultiplication(int n, int A[n][n], int B[n][n], int C[n][n])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			C[i][j] = 0;

			for(int k = 0; k < n; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
}

int main()
{
	int n;
	clock_t start, end;
	double cpu_time_used;

	printf("\n Enter the size of matrix : ");
	scanf("%d", &n);

	srand(time(NULL));

	int A[n][n], B[n][n], C[n][n];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 10;
		}
	}


	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			B[i][j] = rand() % 10;
		}
	}

	printf("\n The randomly generated Matrix A is : \n\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("\t%d", A[i][j]);
		}
		printf("\n");
	}

	printf("\n The randomly generated Matrix B is : \n\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("\t%d", B[i][j]);
		}
		printf("\n");
	}

	start = clock();
	matrixMultiplication(n, A, B, C);
	end = clock();

	printf("\n The resultant Matrix C =  A * B is : \n\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("\t%d", C[i][j]);
		}
		printf("\n");
	}

	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;

	printf("\n Time Taken : %lf micro-seconds \n\n", cpu_time_used * 1000000.0);

	return 0;
}
