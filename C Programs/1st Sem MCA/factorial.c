// Program to find factorial of a number

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
	printf("\n-------------------------------");
	printf("\n     FACTORIAL OF A NUMBER     ");
	printf("\n    -----------------------    ");
	printf("\n\n Enter a number : ");
	scanf("%d",&n);
	printf("\n %d ! = %d",n,fact(n));
	printf("\n\n-------------------------------\n\n");
	return 0;
}
