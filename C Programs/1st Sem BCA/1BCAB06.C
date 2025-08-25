/*program to convert the given decimal number to binary number*/
#include<stdio.h>

int main()
{
 long int n,r,s,i;
 
 printf("\nEnter a number : ");
 scanf("%ld",&n);
 s=0;
 i=1;
 while(n!=0)
 {
  r=n%2;
  s=s+i*r;
  n=n/2;
  i=i*10;
 }
 printf("the binary equivalent is %ld",s);
 return 0;
}