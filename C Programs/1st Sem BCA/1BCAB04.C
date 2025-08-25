/*program to reverse a given number*/
#include<stdio.h>

int main()
{
 int n,r,s;
 
 printf("\nEnter a number : ");
 scanf("%d",&n);
 s=0;
 while(n!=0)
 {
  r=n%10;
  s=s*10+r;
  n=n/10;
 }
 printf("reversed number is : %d",s);
 return 0;
}