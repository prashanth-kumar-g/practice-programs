// Program to print left half pyramid star pattern

#include<stdio.h>

int main()
{
	int n;
	printf("\n---------------------------------------------------------");
	printf("\n              LEFT HALF PYRAMID STAR PATTERN             ");
	printf("\n             --------------------------------            ");
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
	printf("---------------------------------------------------------\n\n");
	return 0;
}

