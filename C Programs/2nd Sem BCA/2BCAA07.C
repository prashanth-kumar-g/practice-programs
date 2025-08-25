/*program to find the gcd of two numbers using recursion*/
#include<stdio.h>

int gcd(int,int);
int main()
{
 int m,n;
 
 printf("\nEnter two numbers\n");
 scanf("%d %d",&m,&n);
 printf("GCD of %d and %d is %d",m,n,gcd(m,n));
 return 0;
}
int gcd(int x,int y)
{
 if(y==0)
  return(x);
 else if(y>x)
  return(gcd(y,x));
 else
  return(gcd(y,x%y));
}


















