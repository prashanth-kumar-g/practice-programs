// Program to print pascal's triangle number pattern

#include<stdio.h>

int fact(int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	else
	{
		return n*fact(n-1);
	}
}

int main()
{
	int n;
	printf("\n------------------------------------------------------------");
	printf("\n              PASCAL'S TRIANGLE NUMBER PATTERN              ");
	printf("\n             ----------------------------------             ");
	printf("\n\nEnter the number of lines : ");
	scanf("%d",&n);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int k=1;k<=n-i;k++)
		{
			printf(" ");
		}
		for(int j=0;j<=i;j++)
		{
			printf("%d ",fact(i)/(fact(i-j)*fact(j)));
		}
		printf("\n");
	}
	printf("------------------------------------------------------------\n\n");
	return 0;
}

