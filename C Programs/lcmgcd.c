#include<stdio.h>
int gcd(int m, int n)
{
	if(m==n)
	{
		return m;
	}
	else if(n>m)
	{
		return gcd(n,m);
	}
	else if(n==0)
	{
		return m;
	}
	else
	{
		return gcd(n,m%n);
	}
}
int main()
{
	int m,n,l,g;
	printf("\nEnter 1st number : ");
	scanf("%d",&m);
	printf("Enter 2nd number : ");
	scanf("%d",&n);
	g=gcd(m,n);
	l=m*n/g;
	printf("\nLCM of %d and %d = %d",m,n,l);
	printf("\nGCD of %d and %d = %d",m,n,g);
	printf("\n\n");
	return 0;
}
