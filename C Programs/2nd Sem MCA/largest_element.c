#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int largestElement(int a[], int n)
{
	int largest = a[0];

	for(int i = 1; i < n; i++)
	{
		if(a[i] > largest)
		{
			largest = a[i];
		}
	}

	return largest;
}

int main()
{
	int n, key, largest;
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
		printf("%d ", a[i]);
	}

	start = clock();
	largest = largestElement(a, n);
	end = clock();

	cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;

	printf("\n\n The largest Element in the array is : %d\n", largest);

	printf("\n Time Taken : %lf micro-seconds\n\n", cpu_time_used * 1000000.0);

	return 0;
}
