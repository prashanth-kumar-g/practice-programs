// Program to print right half butterfly star pattern

#include<stdio.h>

int main()
{
	int n;
	printf("\n-------------------------------------------------------------");
	printf("\n              RIGHT HALF BUTTERFLY STAR PATTERN              ");
	printf("\n             -----------------------------------             ");
	printf("\n\nEnter the number of lines : ");
	scanf("%d",&n);
	printf("\n");
	int k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if((i+j)%2==0)
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("-------------------------------------------------------------\n\n");
	return 0;
}

