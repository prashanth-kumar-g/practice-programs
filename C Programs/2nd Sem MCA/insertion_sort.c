#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int arr[], int n)
{
	int i, j, key;

	for(i = 1; i <= n - 1; i++)
	{
		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int main()
{
	int n;
	clock_t start, end;
	double cpu_time_used;

	printf("\n Enter the size of array : ");
	scanf("%d", &n);

	srand(time(NULL));
	int a[n];
	int count = 0;
	while(count < n)
	{
		int num = rand() % 1000;
		int isUnique = 1;

		for(int i = 0; i < count; i++)
		{
			if(a[i] == num)
			{
				isUnique = 0;
				break;
			}
		}

		if(isUnique)
		{
			a[count++] = num;
		}
	}

	printf("\n The randomly generated unique array is : ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}

	start = clock();
	insertionSort(a, n);
	end = clock();

	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;

	printf("\n\n The sorted array using insertion sort is : ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}


	printf("\n\n Time Taken : %lf micro-seconds\n\n", cpu_time_used * 1000000.0);

	return 0;
}
