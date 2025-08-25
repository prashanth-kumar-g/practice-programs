/*program to calculate nCr (combination) value using function*/
#include<stdio.h>

int main()
{
 int nCr,n,r;
 
 printf("\nEnter value of n and r\n");
 scanf("%d %d",&n,&r);
 nCr=fact(n)/(fact(n-r)*fact(r));
 printf("\n%dC%d = %d",n,r,nCr);
 return 0;
}
int fact(int x)
{
 int i,fact=1;
 for(i=1;i<=x;i++)
 {
  fact=fact*i;
 }
 return(fact);
}