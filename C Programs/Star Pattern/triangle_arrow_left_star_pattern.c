// Program to print triangle shaped left arrow star pattern

#include<stdio.h>

int main()
{
	int n;
	printf("\n-------------------------------------------------------------");
	printf("\n           TRIANGLE SHAPED LEFT ARROW STAR PATTERN           ");
	printf("\n          -----------------------------------------          ");
	printf("\n\nEnter the number of lines : ");
	scanf("%d",&n);
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n-i;k++)
		{
			printf("  ");
		}
		for(int j=1;j<=i;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int k=1;k<=n-i;k++)
		{
			printf("  ");
		}
		for(int j=1;j<=i;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("-------------------------------------------------------------\n\n");
	return 0;
}

