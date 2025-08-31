#include<stdio.h>

int main()
{
	int n;

	printf("\n Enter the size : ");
	scanf("%d", &n);

	int arr[n];
	printf("\n Enter the elements : ");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int target;
	printf("\n Enter the target sum : ");
	scanf("%d", &target);

	int total_subsets = 1 << n;
	for(int mask = 0; mask < total_subsets; mask++)
	{
		int sum = 0;
		printf("\n {");

		for(int j = 0; j < n; j++)
		{
			if( mask & (1 << j) )
			{
				sum = sum + arr[j];
				printf(" %d,", arr[j]);
			}
		}

		printf(" } --> sum = %d", sum);

		if(sum == target)
		{
			printf(" --> matches target!");
		}

		printf("\n");
	}

	printf("\n");

	return 0;
}
