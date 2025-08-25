#include<stdio.h>

long double factorial(long double n)
{
	long double fact=1;
	for(long double i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	return fact;
}

int main()
{
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n Generate formula for (a + b)^n \n");
	long double n;
	printf("\n Enter the value of n : ");
	scanf("%Lf",&n);
	printf("\n (a + b)^%.0Lf  =  ",n);
	for(long double i=0;i<=n;i++)
	{
		if(i==0)
		{
			printf("a^%.0Lf  +  ",n);
		}
		else if(i==1)
		{
			if(n==2)
			{
				printf("%.0Lf a b  +  ",n);
			}
			else
			{
				printf("%.0Lf a^%.0Lf b  +  ",n,n-1);
			}
		}
		else if(i==(n-1))
		{
			printf("%.0Lf a b^%.0Lf  +  ",n,n-1);
		}
		else if(i==n)
		{
			printf("b^%.0Lf",n);
		}
		else
		{
			printf("%.0Lf a^%.0Lf b^%.0Lf  +  ",factorial(n)/(factorial(i)*factorial(n-i)),n-i,i);
		}
	}
	printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}
