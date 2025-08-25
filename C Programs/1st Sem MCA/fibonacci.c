// Program to generate fibonnaci series

#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
	if(n==0)
	{
		return 0;
	}
	else if(n==1)
	{
		return 1;
	}
	else
	{
		return fib(n-1)+fib(n-2);
	}
}

int main()
{
	int n;
	printf("\n-----------------------------------------------------------------------");
	printf("\n                          FIBONACCI SERIES                             ");
	printf("\n                         ------------------                            ");
	printf("\n\n Enter the number of terms : ");
	scanf("%d",&n);
	printf("\n The fibonnaci series is : ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",fib(i));
	}
	printf("\n\n-----------------------------------------------------------------------\n\n");
	return 0;
}
