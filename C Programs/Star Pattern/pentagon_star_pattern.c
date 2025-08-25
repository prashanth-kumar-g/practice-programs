// Program to print pentagon shaped star pattern

#include<stdio.h>

int main()
{
	int n;
	printf("\n----------------------------------------------------");
	printf("\n            PENTAGON SHAPED STAR PATTERN            ");
	printf("\n           ------------------------------           ");
	printf("\n\nEnter the number of lines : ");
	scanf("%d",&n);
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n-i;k++)
		{
			printf("  ");
		}
		for(int j=1;j<=2*i-1;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=2*n-1;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	printf("----------------------------------------------------\n\n");
	return 0;
}
