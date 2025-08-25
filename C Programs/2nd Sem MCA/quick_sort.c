#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];

	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);

	return i + 1;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);

		quickSort(arr, pi + 1, high);
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
	quickSort(a, 0, n - 1);
	end = clock();

	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;

	printf("\n\n The sorted array using quick sort is : ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}


	printf("\n\n Time Taken : %lf micro-seconds\n\n", cpu_time_used * 1000000.0);

	return 0;
}
