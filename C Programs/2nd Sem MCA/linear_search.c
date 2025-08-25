#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int linearSearch(int a[], int n, int key)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == key)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int n, key, index;
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

	printf("\n\n Enter the element to be searched : ");
	scanf("%d", &key);

	start = clock();
	index = linearSearch(a, n, key);
	end = clock();

	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;

	if(index == -1)
	{
		printf("\n Element %d do not exist in the array \n", key);
	}
	else
	{
		printf("\n The first occurance of Element %d is found at index : %d\n", key, index);
	}

	printf("\n Time Taken : %lf micro-seconds\n\n", cpu_time_used * 1000000.0);

	return 0;
}
