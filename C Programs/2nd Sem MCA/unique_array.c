#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int uniqueArray(int a[], int n)
{
	for(int i = 0; i < n - 2; i++)
	{
		for(int j = i + 1; j < n - 1; j++)
		{
			if(a[i] == a[j])
			{
				return 0;
			}
		}
	}

	return 1;
}

int main()
{
	int n, key, result;
	clock_t start, end;
	double cpu_time_used;

	printf("\n Enter the size of array : ");
	scanf("%d", &n);

	srand(time(NULL));
	int a[n];
	for(int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}

	printf("\n The randomly generated array is : ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	start = clock();
	result = uniqueArray(a, n);
	end = clock();

	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;

	if(result)
	{
		printf("\n\n The array has unique elements \n");
	}
	else
	{
		printf("\n\n The array has duplicate elements \n");
	}

	printf("\n Time Taken : %lf micro-seconds\n\n", cpu_time_used * 1000000.0);

	return 0;
}
