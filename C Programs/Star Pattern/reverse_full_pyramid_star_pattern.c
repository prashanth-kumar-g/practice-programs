// Program to print reverse full pyramid star pattern

#include<stdio.h>

int main()
{
	int n;
	printf("\n------------------------------------------------------");
	printf("\n           REVERSE FULL PYRAMID STAR PATTERN          ");
	printf("\n          -----------------------------------         ");
	printf("\n\nEnter the number of lines : ");
	scanf("%d",&n);
	printf("\n");
	for(int i=n;i>=1;i--)
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
	printf("------------------------------------------------------\n\n");
	return 0;
}
