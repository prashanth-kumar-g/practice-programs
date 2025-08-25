#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int n)
{
	int i, j, temp;
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
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
	bubbleSort(a, n);
	end = clock();

	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;

	printf("\n\n The sorted array using bubble sort is : ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}


	printf("\n\n Time Taken : %lf micro-seconds\n\n", cpu_time_used * 1000000.0);

	return 0;
}
