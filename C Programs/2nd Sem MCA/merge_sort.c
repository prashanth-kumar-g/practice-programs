#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int low, int mid, int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int left[n1], right[n2];

	for (int i = 0; i < n1; i++)
	{
		left[i] = arr[low + i];
	}

	for (int j = 0; j < n2; j++)
	{
		right[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = low;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}

		k++;
	}

	while (i < n1)
	{
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int low, int high)
{
	if (low < high)
	{
        	int mid = (low + high) / 2;

        	mergeSort(arr, low, mid);

        	mergeSort(arr, mid + 1, high);

        	merge(arr, low, mid, high);
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
	mergeSort(a, 0, n - 1);
	end = clock();

	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;

	printf("\n\n The sorted array using merge sort is : ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}


	printf("\n\n Time Taken : %lf micro-seconds\n\n", cpu_time_used * 1000000.0);

	return 0;
}
