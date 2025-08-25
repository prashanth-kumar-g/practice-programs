// Program to print left leaned parallelogram shaped star pattern

#include<stdio.h>

int main()
{
	int r,c;
	printf("\n-----------------------------------------------------------");
	printf("\n       LEFT LEANED PARALLELOGRAM SHAPED STAR PATTERN       ");
	printf("\n      -----------------------------------------------      ");
	printf("\n\nEnter the number of rows : ");
	scanf("%d",&r);
	printf("Enter the number of columns : ");
	scanf("%d",&c);
	printf("\n");
	for(int i=1;i<=r;i++)
	{
		for(int k=1;k<=r-i;k++)
		{
			printf("  ");
		}
		for(int j=1;j<=c;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------\n\n");
	return 0;
}

